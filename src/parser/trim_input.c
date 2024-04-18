/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:45:54 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 14:29:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_len(const char *result)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(result);
	while (result[i])
	{
		if (!quotes(result[i]) && result[i] == '|')
		{
			if (i > 0 && result[i - 1] == ' ')
				len--;
			if (result[i + 1] == ' ')
				len--;
		}
		i++;
	}
	return (len);
}
static char	*rm_pipe_spaces(const char *input)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = get_len(input);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		result[j] = input[i];
		if (!quotes(result[i]) && result[i] == '|')
		{
			if (i > 0 && result[i - 1] == ' ')
			{
				j--;
				result[j] = input[i];
			}
			if (result[i + 1] == ' ')
				i++;
		}
		i++;
		j++;
	}
	return (result);
}

char	*trim_input(const char *input)
{
	char *result;

	result = ft_trim_input(input);
	if (!result)
		return (NULL);

	result = rm_pipe_spaces(result);

	// len = get_len(input);
	// result = (char *)calloc(len + 1, sizeof(char));
	// if (!result)
	// 	return (NULL);
	// result = fill(result, input);
	return (result);
}