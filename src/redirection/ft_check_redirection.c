/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/01 15:55:25 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// int	checker(char *command)
// {
	
// }

// //-1 does not found a '>'
void	ft_check_redirection(t_shell *data)
{
	int		i;
	// int		j;
	// char	*pos;

	i = 0;
	
	while (data->pipes[i])
	{
		printf("Command: [%s]\n", data->pipes[i]);
		if (ft_strchr((const char *)data->pipes[i], '>'))
		{
			printf("Redirection founded\n");
			ft_create_archive(data, i);
			printf("exit_redirection\n");
		}
		i++;
	}
	
	// while (data->pipes[i])
	// {
	// 	j = 0;
	// 	while (data->pipes[i][j])
	// 	{
	// 		if (data->pipes[i][j] == '>')
				
	// 		j++;
	// 	}
	// 	i++;
	// }
	//Falta mucho parseo aqui aquí
}
