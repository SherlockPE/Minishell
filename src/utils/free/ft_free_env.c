/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/03/13 17:49:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_free_node(void *data)
{
	t_env	*env;

	env = (t_env *)data;
	free(env->name);
	free(env->value);
	free(data);
}

void	ft_free_env(t_list *env)
{
	ft_lstclear(&env, ft_free_node);
}
