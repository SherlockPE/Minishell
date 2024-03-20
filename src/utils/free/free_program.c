/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:41:30 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/20 17:07:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_program(t_shell *data)
{
	ft_lstclear(&data->env, free);
	free_input(data);
	rl_clear_history();
}
