/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:45:54 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/25 14:38:46 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_len(const char *input)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(input);
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == '|')
		{
			if (i > 0 && input[i - 1] == ' ')
				len--;
			if (input[i + 1] == ' ')
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
	char	*result;

	result = (char *)ft_calloc(get_len(input) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (input[++i])
	{
		result[j] = input[i];
		if (!quotes(input[i]) && input[i] == '|')
		{
			if (i > 0 && input[i - 1] == ' ')
			{
				j--;
				result[j] = input[i];
			}
			if (input[i + 1] == ' ')
				i++;
		}
		j++;
	}
	return (result);
}

char	*trim_input(const char *input)
{
	char	*result;
	char	*temp;

	temp = ft_trim_input(input);
	if (!temp)
		return (NULL);
	result = rm_pipe_spaces(temp);
	free(temp);
	if (!result)
		return (NULL);
	return (result);
}
