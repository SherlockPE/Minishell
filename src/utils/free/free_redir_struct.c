/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:06:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/01 16:12:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_redir_struct(t_redir *red)
{
	ft_free_array(red->com_argv);
}