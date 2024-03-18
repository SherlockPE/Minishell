/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/18 17:41:46 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_echo(t_shell *data)
{
	if (!data->com->argv[1])
		return ;
	if (!ft_strncmp(data->com->argv[1], "-n", 2))
	{
		if (data->com->argv[2])
			printf("%s", data->com->argv[2]);
	}
	else
		printf("%s\n", data->com->argv[1]);
}

/* void	ft_echo(t_shell *data)
{
	int	i;

	if (!data->argv[1])
		return ;
	i = 2;
	if (!ft_strncmp(data->argv[1], "-n", 2))
	{
		while (data->argv[i])
		{
			printf("%s", data->argv[i]);
			i++;
			if (data->argv[i])
				printf(" ");
		}
	}
	else
	{
		while (data->argv[i])
		{
			printf("%s", data->argv[i]);
			i++;
			if (data->argv[i])
				printf(" ");
		}
		printf("\n");
	}
}
 */