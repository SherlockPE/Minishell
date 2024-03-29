/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:42:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	remove_env(char *name, size_t len_name, t_list *env, t_shell *data)
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
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
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

void	ft_unset(t_shell *data)
{
	char	*name;

	name = data->com->argv[1];
	if (!name)
		return ;
	remove_env(name, ft_strlen(name), data->env, data);
}
