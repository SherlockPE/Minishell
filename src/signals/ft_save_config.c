/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:52:29 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/04/12 14:14:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void    ft_save_config(t_shell *data)
{
	if (tcgetattr(STDIN_FILENO, &data->init_conf) == -1)
		perror("tcgetattr");
}
