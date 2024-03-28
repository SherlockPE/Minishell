/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/03/28 18:53:48 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_env(t_shell *data)
{
	int		i;
	char	**envp;
	t_list	*env;

	i = ft_lstsize(data->env);
	envp = ft_calloc(i + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	env = data->env;
	while (env)
	{
		envp[i] = (char *)env->content;
		i++;
		env = env->next;
	}
	envp[i] = 0;
	return (envp);
}

// static void	child_signal(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		printf("\n");
// 	}
// 	else if (signal == SIGQUIT)
// 	{
// 		printf("\n");
// 	}
// }

static void	child_execve(t_shell *data, char *bin_path, char **envp)
{
	if (execve(bin_path, data->com->argv, envp) == -1)
		perror("execve");
	free_program(data);
	free(envp);
	free(bin_path);
	exit(EXIT_FAILURE);
}

static void	new_child_execve(t_shell *data, char *bin_path, char **envp)

{
	pid_t	id;
	int		wstatus;

	id = fork();
	if (id == -1)
		return (perror("fork"));
	if (id == 0)
	{
		if (execve(bin_path, data->com->argv, envp) == -1)
			perror("execve");
		free_program(data);
		free(envp);
		free(bin_path);
		exit(EXIT_FAILURE);
	}
	waitpid(id, &wstatus, 0);
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
}

// static void	new_child_execve(t_shell *data, char *bin_path, char **envp)
// {
// 	pid_t	id;
// 	int		wstatus;

// 	id = fork();
// 	if (id == -1)
// 		return (perror("fork"));
// 	if (id == 0)
// 	{
// 		signal(SIGINT, child_signal);
// 		signal(SIGQUIT, child_signal);
// 		if (execve(bin_path, data->com->argv, envp) == -1)
// 		{
// 			free_program(data);
// 			free(envp);
// 			free(bin_path);
// 			perror("execve");
// 			exit(EXIT_FAILURE);
// 		}
// 		free_program(data);
// 		free(envp);
// 		free(bin_path);
// 		exit(EXIT_SUCCESS);
// 	}
// 	waitpid(id, &wstatus, 0);
// 	if (WIFEXITED(wstatus))
// 		data->exit_code = WEXITSTATUS(wstatus);
// }

// char	*temp;

// if (*command == '.' && *command + 1 == '/')
// {
// 	temp = ft_substr(command, 0, ft_strlenchr(command, ' '));
// 	bin_path = ft_strdup(temp);
// 	free(temp);
// 	if (access(bin_path, X_OK) == 0)
// 		printf("Tiene acceso\n");
// 	else
// 		printf("No tiene acceso\n");
// 	free(argv[0]);
// 	argv[0] = ft_strdup(bin_path + 2);
// }
// else
// 	bin_path = ft_check_bin(data, argv[0]);
void	ft_exec_bin(t_shell *data)
{
	char	*bin_path;
	char	**envp;

	bin_path = ft_check_bin(data);
	if (!bin_path)
	{
		if ((data->com->argv[0][0] == '.' && data->com->argv[0][1] == '/') 
			|| data->com->argv[0][0] == '/')
		{
			bin_path = ft_strdup(data->com->argv[0]);
			if (!bin_path)
				ft_exit_program(data, "malloc");
		}
		else
		{
			ft_putstr_fd(data->com->argv[0], 2);	
			ft_putstr_fd(" : command not found\n", 2);
			return ;
		}
		// return ((void)printf("[%s] : command not found\n", data->com->argv[0]));
	}
	envp = get_env(data);
	if (!envp)
	{
		free(bin_path);
		ft_exit_program(data, "malloc");
	}
	if (data->com->pid == 0)
		child_execve(data, bin_path, envp);
	else if (bin_path)
		new_child_execve(data, bin_path, envp);
	free(envp);
	free(bin_path);
}
