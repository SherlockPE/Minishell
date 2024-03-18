/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:50:11 by albartol         ###   ########.fr       */
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
	if (execve(bin_path, data->com->argv, envp) == -1)
		perror("execve");
	free_program(data);
	free(envp);
	free(bin_path);
	exit(EXIT_FAILURE);
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
	{
		printf("[%s] : command not found\n", data->com->argv[0]);
		free_program(data);
		exit(EXIT_FAILURE);
	}
	envp = get_env(data);
	if (!envp)
	{
		free(bin_path);
		ft_exit_program(data, "malloc");
	}
	child_execve(data, bin_path, envp);
}
