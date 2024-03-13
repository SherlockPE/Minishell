/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/03/13 17:45:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void ft_print_array(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		printf("a[%d]: %p\n", i, a[i]);
	printf("----------\n");
}

static void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static char	**ft_get_env(t_shell *data)
{
	int		len;
	int		i;
	char	**envp;
	t_list	*env;
	char	*env_name;
	char	*env_value;

	len = ft_lstsize(data->env);
	envp = ft_calloc(len + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	env = data->env;
	while (i < len)
	{
		env_name =  ((t_env *)env->content)->name;
		env_value =  ((t_env *)env->content)->value;
		envp[i] = ft_strjoin(env_name, env_value);
		if (!envp[i])
		{
			ft_free_array(envp);
			return (NULL);
		}
		i++;
		env = env->next;
	}
	envp[i] = 0;
	return (envp);
}

void	ft_exec_bin(t_shell *data, const char *command)
{
	char	*bin_path;
	char	**argv;
	char	**envp;
	pid_t	id;

	argv = ft_split(command, ' ');
	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	bin_path = ft_check_bin(data, argv[0]);
	if (!bin_path)
	{
		printf("%s : command not found\n", argv[0]);
		ft_free_array(argv);
		return ;
	}
	envp = ft_get_env(data);
	if (!envp)
	{
		ft_free_array(argv);
		free(bin_path);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == 0)
	{
		if (execve(bin_path, argv, envp) == -1)
			perror(NULL);
		exit(0);
	}
	waitpid(-1, NULL, 0);
	ft_free_array(argv);
	ft_free_array(envp);
	free(bin_path);
}
