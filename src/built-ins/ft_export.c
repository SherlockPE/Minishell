/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:42:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(t_shell *data)
{
	if (!data->com->argv[1])
		return (ft_env(data));
	if (ft_strchr(data->com->argv[1], '='))
		ft_set_env_value(data->com->argv[1], data);
}
