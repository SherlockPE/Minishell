/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:41:30 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/16 11:43:10 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_program(t_shell *data)
{
	ft_lstclear(&data->env, free);
	free_input(data);
}
