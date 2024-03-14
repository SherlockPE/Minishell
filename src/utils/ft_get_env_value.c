/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:03:06 by albartol          #+#    #+#             */
/*   Updated: 2024/03/14 15:03:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_get_env_value(char *name, t_list *env)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;

	len_name = ft_strlen(name);
	while (env)
	{
		env_name = ((t_env *)env->content)->name;
		len_env = ft_strlen(env_name) - 1;
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
			return (((t_env *)env->content)->value);
		env = env->next;
	}
	return (NULL);
}
