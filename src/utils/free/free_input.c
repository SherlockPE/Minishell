/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:43:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/18 17:35:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_input(t_shell *data)
{
	free(data->command);
	// ft_free_array(data->argv);
	ft_free_array(data->pipes);
	if (data->com)
		ft_free_array(data->com->argv);
	data->command = 0;
	// data->argv = 0;
	data->pipes = 0;
}
