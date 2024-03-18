/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 12:34:22 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	search_and_remove_env(char *name, t_list *env, t_shell *data)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;
	t_list	*prev;
	short	i;

	len_name = ft_strlen(name);
	i = 0;
	while (env)
	{
		env_name = (char *)env->content;
		len_env = ft_strlenchr(env_name, '=') - 1;
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
		{
			if (i == 0)
				data->env = env->next;
			else
				prev->next = env->next;
			free(env->content);
			free(env);
			return ;
		}
		prev = env;
		env = env->next;
		i = 1;
	}
}

void	ft_unset(t_shell *data)
{
	if (!data->argv[1])
		return ;
	search_and_remove_env(data->argv[1], data->env, data);
}
