/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:16 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 15:44:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_print_node(void *node)
{
	t_env	*env;

	env = (t_env *)node;
	printf("%s=%s\n", env->name, env->value);
}

void	ft_env(t_shell *data)
{
	ft_lstiter(data->env, ft_print_node);
}
