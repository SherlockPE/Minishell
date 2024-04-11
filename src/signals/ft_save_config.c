/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:52:29 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/04/11 23:58:31 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void    ft_save_config(t_shell *data)
{
    if (tcgetattr(STDIN_FILENO, &data->init_conf) == -1)
        perror("tcgetattr");
}
