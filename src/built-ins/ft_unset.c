/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:52:29 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	rm_env(const char *name, size_t len, t_list *env, t_shell *data)
{
	size_t	len_env;
	t_list	*prev;
	char	*env_name;
	short	first;

	first = 0;
	while (env)
	{
		env_name = (char *)env->content;
		len_env = ft_strlenchr(env_name, '=') - 1;
		if (len == len_env && !ft_strncmp(name, env_name, len))
		{
			if (first == 0)
				data->env = env->next;
			else
				prev->next = env->next;
			free(env->content);
			free(env);
			return ;
		}
		prev = env;
		env = env->next;
		first = 1;
	}
}

void	ft_unset(char **argv, t_shell *data)
{
	int		i;
	int		j;
	char	*name;

	i = -1;
	data->exit_code = EXIT_SUCCESS;
	while (argv[++i])
	{
		j = 0;
		name = argv[i];
		while (name[j])
		{
			if (!ft_isalnum(name[j]) && name[j] != '_')
			{
				ft_putstr_fd("unset: \'", STDERR);
				ft_putstr_fd(name, STDERR);
				ft_putstr_fd("\': is not a valid identifier\n", STDERR);
				data->exit_code = EXIT_FAILURE;
				break ;
			}
			j++;
		}
		if ((j > 0 && !name[j]) || ft_isalnum(name[j]) || name[j] == '_')
			rm_env(name, ft_strlen(name), data->env, data);
	}
}
