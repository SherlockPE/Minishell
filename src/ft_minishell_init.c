/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/03/27 15:35:30 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_minishell_init(t_shell *data, char **env)
{
	data->env = 0;
	data->com = 0;
	data->input = 0;
	data->pipes = 0;
	data->prompt = 0;
	data->exit_code = 0;
	ft_init_env(data, env);
}
