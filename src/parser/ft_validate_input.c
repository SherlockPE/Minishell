/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 14:50:34 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	ft_validate_input(t_shell *data)
{
	int		i;
	char	*com;

	i = 0;
	com = data->command;
	if (!com || !*com)
		return (1);
	while (com[i])
	{
		if (com[i] == '|' || com[i] == '&')
		{
			printf("syntax error: unexpected token '%c'\n", com[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
