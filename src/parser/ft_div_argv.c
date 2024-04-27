/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:45:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/27 15:44:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_div_argv(t_shell *data)
{
	int	i;

	i = 0;
	while (i < data->com_len)
	{
		data->com[i].argv = ft_split_quotes(data->com[i].com, NOT_VAL);
		if (!data->com[i].argv)
			return (ft_exit_funct("malloc", EXIT_FAILURE));
		i++;
	}
	return (EXIT_SUCCESS);
}
