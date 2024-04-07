/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:20:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/07 13:10:02 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
	
static char	*get_input(void)
{
	char	*new_input;

	new_input = readline("> ");
	if (!new_input)
	{
		// red->success = 0;
		// free(red->file_name);
		// free(final_str);
		// free_input(data);
		// data->input = (char *)ft_calloc(1, sizeof(char));
		// if (!data->input)
		// 	ft_exit_program(data, "malloc");
		ft_putstr_fd("unexpected EOF while looking for \"\'\n", STDERR);
		return (NULL);
	}
	return (new_input);
}

static int	check_input(char *new_input, char *limit)
{
	size_t	input_len;

	input_len = ft_strlen(new_input);
	if (input_len != ft_strlen(limit))
		return (0);
	if (ft_strncmp(new_input, limit, input_len))
		return (0);
	return (1);
}

static void	new_stdin(char *final_str)
{
	int	fd;

	fd = open(".here_doc", O_WRONLY | O_TRUNC | O_CREAT, FILE_PERM);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	ft_putstr_fd(final_str, fd);
	close(fd);
	free(final_str);
	fd = open(".here_doc", O_RDONLY, FILE_PERM);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	if (dup2(fd, STDIN_FILENO))
	{
		close(fd);
		// ft_exit_program(data, "dup2");
		perror("dup2");
		return ;
	}
	close(fd);
}

void	ft_get_limit(t_shell *data, t_redir *red)
{
	char	*final_str;
	char	*temp_str;
	char	*aux_str;
	char	*new_input;

	final_str = 0;
	ft_get_archive_name(data, red);
	while (1)
	{
		new_input = get_input();
		if (!new_input || check_input(new_input, red->file_name))
			break ;
		temp_str = ft_charjoin(new_input, '\n');
		free(new_input);
		if (!temp_str)
		{
			free(final_str);
			free(red->file_name);
			ft_exit_program(data, "malloc");
		}
		aux_str = final_str;
		final_str = ft_strjoin(final_str, temp_str);
		free(temp_str);
		free(aux_str);
		if (!final_str)
		{
			free(red->file_name);
			ft_exit_program(data, "malloc");
		}
	}
	free(red->file_name);
	free(new_input);
	new_stdin(final_str);
}
