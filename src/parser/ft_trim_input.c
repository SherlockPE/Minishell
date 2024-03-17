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
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (quotes(input[i]))
			len++;
		else if (input[i] != ' ' || (i > 0 && input[i - 1] != ' '))
			len++;
		i++;
	}
	return (len);
}

void	ft_trim_input(t_shell *data)
{
	char	*str;
	char	*com;
	int		i;
	int		j;

	i = 0;
	j = 0;
	com = data->command;
	str = ft_calloc(ft_count_len(com) + 1, 1);
	if (!str)
		ft_exit_program(data, "malloc");
	while (com[i])
	{
		if (quotes(com[i]))
			str[j++] = com[i];
		else if (com[i] != ' ' || (i > 0 && com[i - 1] != ' '))
			str[j++] = com[i];
		i++;
	}
	com = ft_strtrim(str, " ");
	free(str);
	if (!com)
		ft_exit_program(data, "malloc");
	free(data->command);
	data->command = com;
}
