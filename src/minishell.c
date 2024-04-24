/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/23 14:19:44 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **env)
{
	t_shell	data;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("Too many arguments\n", STDERR);
		return (EXIT_SUCCESS);
	}
	ft_minishell_init(&data, env);
	ft_minishell_loop(&data);
	return (EXIT_SUCCESS);
}
