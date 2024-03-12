/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:27:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/12 18:53:39 by flopez-r         ###   ########.fr       */
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

char	*ft_trim_input(t_shell *data, char *input)
{
	char	*str;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(ft_count_len(input) + 1, 1);
	if (!str)
	{
		perror(NULL);
		exit(errno);
	}
	while (input[i])
	{	
		if (input[i] != ' ')
			str[j++] = input[i];
		else if (i > 0 && input[i - 1] != ' ')
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
	// printf("%s\n", str2);
	return (str2);
}


void    ft_parser(t_shell *data, char *input)
{
	char	*command;

	command = ft_trim_input(data, input);
	if (*command)
	{
		ft_exec_command(command, data);
		add_history(command);
	}
}
