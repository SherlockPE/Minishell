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

static void	ft_child_signal(int signal)
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

static size_t	ft_strlenchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i + 1);
	return (0);
}

void	ft_exec_bin(t_shell *data, const char *command)
{
	char	*bin_path;
	char	**argv;
	char	**envp;
	pid_t	id;
	char	*current_dir;
	char	*temp;

	if (*command == '.')
	{
		temp = ft_substr(command, 0, ft_strlenchr(command, ' '));
		current_dir = getcwd(NULL, 0);
		if (!current_dir)
		{
			free(temp);
			return (perror(NULL));
		}
		bin_path = ft_strjoin(current_dir, temp + 1);
		free(current_dir);
		free(temp);
	}
	else
		bin_path = ft_check_bin(data, argv[0]);
	if (!bin_path)
	{
		printf("%s : command not found\n", argv[0]);
		ft_free_array(argv);
		return ;
	}
	argv = ft_split(command, ' ');
	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
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
		signal(SIGINT, ft_child_signal);
		if (execve(bin_path, argv, envp) == -1)
			perror(NULL);
		exit(0);
	}
	waitpid(-1, NULL, 0);
	ft_free_array(argv);
	ft_free_array(envp);
	free(bin_path);
}
