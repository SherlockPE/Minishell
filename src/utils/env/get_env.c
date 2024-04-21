/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:35:11 by albartol          #+#    #+#             */
/*   Updated: 2024/04/21 11:37:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_env(t_shell *data)
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
