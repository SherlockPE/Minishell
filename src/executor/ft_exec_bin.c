/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/04/13 18:53:55 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_env(t_shell *data)
{
	int		i;
	char	**envp;
	t_list	*env;

	i = ft_lstsize(data->env);
	envp = (char **)ft_calloc(i + 1, sizeof(char *));
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

static void	child_execve(t_shell *data, char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
		perror("execve");
	free_program(data);
	free(envp);
	free(path);
	exit(EXIT_FAILURE);
}

static void	new_child_exec(t_shell *data, char *path, char **argv, char **envp)

{
	pid_t	id;
	int		wstatus;

	id = fork();
	if (id == -1)
		return (perror("fork"));
	if (id == 0)
	{
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		{
			perror("signal");
			free_program(data);
			free(envp);
			free(path);
			exit(EXIT_FAILURE);
		}
		child_execve(data, path, argv, envp);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	waitpid(id, &wstatus, 0);
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
}

static void	execute(t_shell *data, char *path, char **argv)
{
	char	**envp;

	envp = get_env(data);
	if (!envp)
		perror("malloc");
	if (data->child)
		child_execve(data, path, argv, envp);
	else
		new_child_exec(data, path, argv, envp);
	free(envp);
}

void	ft_exec_bin(char **argv, t_shell *data)
{
	char	*bin_path;
	char	*path;

	path = ft_get_env_value("PATH", data->env);
	bin_path = ft_check_bin(argv[0], path);
	if (!bin_path)
	{
		bin_path = ft_strdup(argv[0]);
		if (!bin_path)
		{
			perror("malloc");
			return ;
		}
	}
	execute(data, bin_path, argv);
	free(bin_path);
}
