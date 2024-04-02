/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/04/02 15:11:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(t_shell *data)
{
	if (!data->com->argv[1])
		return (ft_env(data));
	if (data->com->argv[1][0] == '?')
	{
		ft_putstr_fd("export: name not valid\n", STDERR);
		return ;
	}
	if (ft_strchr(data->com->argv[1], '='))
		ft_set_env_value(data->com->argv[1], data);
}
