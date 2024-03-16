/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:03:06 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 12:07:38 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Function filters name in all of the env list and returns
a pointer of the node */
char	*ft_get_env_value(char *name, t_list *env)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;

	len_name = ft_strlen(name);
	while (env)
	{
		env_name = (char *)env->content;
		len_env = ft_strlenchr(env_name, '=') - 1;
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
			return ((char *)env->content + ft_strlenchr(env->content, '='));
		env = env->next;
	}
	return (NULL);
}
