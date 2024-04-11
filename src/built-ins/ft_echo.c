/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/28 18:03:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_echo(t_shell *data)
{
	int	i;

	if (!data->com->argv[1])
		return ((void)printf("\n"));
	i = 1;
	if (!ft_strncmp(data->com->argv[1], "-n", 2))
	{
		i = 2;
		while (data->com->argv[i])
		{
			ft_putstr_fd(data->com->argv[i], STDOUT_FILENO);
			i++;
			if (data->com->argv[i])
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		return ;
	}
	while (data->com->argv[i])
	{
		ft_putstr_fd(data->com->argv[i], STDOUT_FILENO);
		i++;
		if (data->com->argv[i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
