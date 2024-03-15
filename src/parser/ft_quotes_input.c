/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:54:54 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 19:51:35 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	count_len(char *command)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(command);
	while (command[i])
	{
		if (command[i] == '\"' || command[i] == '\'')
			len--;
		i++;
	}
	return (len);
}

char	*ft_fill_new_command(char *new_c, char *command)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (command[i])
	{
		if (command[i] == '\"' || command[i] == '\'')
			i++;
		if (command[i])
		{
			new_c[j] = command[i];
			j++;
			i++;
		}
	}
	free(command);
	return (new_c);
}

void	ft_quotes_input(t_shell *data)
{
	int		len;
	char	*new_command;

	len = count_len(data->command);
	new_command = calloc(len + 1, 1);
	if (!new_command)
		return ;
	new_command = ft_fill_new_command(new_command, data->command);
	data->command = new_command;
}
