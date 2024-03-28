/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/28 20:03:25 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	checker(char *command)
{
	
}

// //-1 does not found a '>'
void	ft_check_redirection(t_shell *data)
{
	int		i;
	int		j;
	char	*pos;

	i = 0;

	while (data->pipes[i])
	{
		j = 0;
		while (data->pipes[i][j])
		{
			if (data->pipes[i][j] == '>')
				
			j++;
		}
		i++;
	}
}