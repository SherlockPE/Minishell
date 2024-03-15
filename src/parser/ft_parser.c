/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 15:11:01 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_count_len(char *input)
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
	// ft_error_exit(data, str);
	if (!str)
	{
		perror(NULL);
		exit(errno);
	}
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
	{
		perror(NULL);
		exit(errno);
	}
	aux = data->command;
	data->command = str2;
	free(aux);
}

void	ft_parser(t_shell *data)
{
	ft_trim_input(data);
}
