/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 13:40:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	search_and_remove_env(char *name, t_list *env)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;
	t_list	*prev;

	len_name = ft_strlen(name);
	while (env)
	{
		env_name = (char *)env->content;
		len_env = ft_strlenchr(env_name, '=') - 1;
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
		{
			prev->next = env->next;
			free(env->content);
			free(env);
			return ;
		}
		prev = env;
		env = env->next;
	}
}

void	ft_unset(t_shell *data)
{
	if (!data->argv[1])
		return ;
	search_and_remove_env(data->argv[1], data->env);
}
