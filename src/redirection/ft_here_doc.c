/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:56 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 14:46:24 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_input(const char *new_input, const char *limit)
{
	size_t	input_len;

	input_len = ft_strlen(new_input);
	if (input_len != ft_strlen(limit))
		return (0);
	if (ft_strncmp(new_input, limit, input_len))
		return (0);
	return (1);
}

static char	*get_limit(const char *com)
{
	char	*limit;
	int		i;

	i = 0;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			break ;
		i++;
	}
	limit = ft_substr(com, 0, i);
	if (!limit)
	{
		perror("malloc");
		return (NULL);
	}
	return (limit);
}

static int	fill_here_doc(const char *limit, int fd, t_shell *data)
{
	char	*aux;
	char	*new_input;
	char	*temp_str;

	while (1)
	{
		new_input = readline("> ");
		if (!new_input || check_input(new_input, limit))
			break ;
		temp_str = ft_charjoin(new_input, '\n');
		free(new_input);
		if (!temp_str)
			return (EXIT_FAILURE);
		aux = ft_expand_str(temp_str, data);
		if (aux != temp_str)
			free(temp_str);
		if (!aux)
			return (EXIT_FAILURE);
		ft_putstr_fd(aux, fd);
		free(aux);
	}
	free(new_input);
	return (EXIT_SUCCESS);
}

static void	child_writer(t_redir *red, const char *com, t_shell *data)
{
	char	*limit;
	int		fd;

	fd = open(red->file_name, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	if (fd == -1)
		ft_exit_program(data, "open");
	limit = get_limit(com);
	if (!limit)
	{
		close(fd);
		unlink(red->file_name);
		ft_exit_program(data, "malloc");
	}
	if (fill_here_doc(limit, fd, data))
	{
		free(limit);
		close(fd);
		unlink(red->file_name);
		ft_exit_program(data, "malloc");
	}
	free(limit);
	close(fd);
	exit(EXIT_SUCCESS);
}

// static void test(int signal)
// {
// 	if (signal != SIGINT)
// 		return ;
// 	ft_putchar_fd('\n', STDOUT);
// 	exit(EXIT_FAILURE);
// }

int	ft_here_doc(t_redir *red, const char *com, t_shell *data)
{
	int		wstatus;
	pid_t	id;

	if (create_tmp_file_name(red))
		return (EXIT_FAILURE);
	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	if (id == 0)
	{
		rl_catch_signals = 1;
		if (signal(SIGINT, SIG_DFL) == SIG_ERR)
			ft_exit_program(data, "signal");
		child_writer(red, com, data);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	waitpid(id, &wstatus, 0);
	ft_handle_signals();
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (ft_putchar_fd('\n', STDOUT));
	return (EXIT_SUCCESS);
}
