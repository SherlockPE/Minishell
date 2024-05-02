/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:30:30 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 16:30:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_expansor(t_shell *data)
{
	int		i;
	char	*new_str;

	i = 0;
	while (i < data->com_len)
	{
		new_str = ft_expand_str(data->com[i].com, data);
		if (!new_str)
			return (EXIT_FAILURE);
		else if (new_str != data->com[i].com)
		{
			free(data->com[i].com);
			data->com[i].com = new_str;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
