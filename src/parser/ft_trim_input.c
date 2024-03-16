/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/16 12:16:34 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_count_len(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] != ' ')
			j++;
		else if (i > 0 && input[i - 1] != ' ')
			j++;
		i++;
	}
	return (j);
}

void	ft_trim_input(t_shell *data)
{
	char	*aux;
	char	*str;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(ft_count_len(data->command) + 1, 1);
	if (!str)
		ft_exit_program(data, NULL);
	while (data->command[i])
	{
		if (data->command[i] != ' ')
			str[j++] = data->command[i];
		else if (i > 0 && data->command[i - 1] != ' ')
			str[j++] = ' ';
		i++;
	}
	str2 = ft_strtrim(str, " ");
	free(str);
	if (!str2)
		ft_exit_program(data, NULL);
	aux = data->command;
	data->command = str2;
	free(aux);
}
