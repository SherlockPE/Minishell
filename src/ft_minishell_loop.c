/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 14:19:08 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_minishell_loop(t_shell *data)
{
	int	manage_exit;

	while (1)
	{
		free_input(data);
		ft_handle_signals();
		manage_exit = ft_get_input(data);
		if (manage_exit == EXIT_FAILURE)
			continue ;
		else if (manage_exit == EXIT_PROGRAM)
			break ;
		if (ft_parser(data) == EXIT_FAILURE)
			continue ;
	}
}
