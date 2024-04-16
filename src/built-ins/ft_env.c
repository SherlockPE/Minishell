/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:16 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:40:51 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_print_node(void *node)
{
	char	*env;

	env = (char *)node;
	// printf("%s\n", env);
	ft_putstr_fd(env, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_env(char **argv, t_shell *data)
{
	if (argv[1])
		ft_putstr_fd("env: too many arguments\n", STDERR);
	else
		ft_lstiter(data->env, ft_print_node);
}
