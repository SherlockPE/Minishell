/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/03/14 17:00:08 by albartol         ###   ########.fr       */
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

static void	child_signal(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
	else if (signal == SIGQUIT)
	{
		printf("\n");
	}
}

static void	child_execve(t_shell *data, char *bin_path, char **envp)
{
	pid_t	id;
	int		wstatus;

	id = fork();
	if (id == -1)
		return (perror("fork"));
	if (id == 0)
	{
		signal(SIGINT, child_signal);
		free(data->command);
		if (execve(bin_path, data->argv, envp) == -1)
			perror(NULL);
		free_program(data);
		exit(EXIT_FAILURE);
	}
	waitpid(id, &wstatus, 0);
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
}

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
		return ((void)printf("[%s] : command not found\n", data->argv[0]));
	envp = get_env(data);
	if (!envp)
	{
		free(bin_path);
		ft_exit_program(data, "malloc");
	}
	child_execve(data, bin_path, envp);
	free(envp);
	free(bin_path);
}
