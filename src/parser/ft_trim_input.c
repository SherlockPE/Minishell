/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_count_len(const char *input)
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

char	*ft_trim_input(const char *input) 
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)ft_calloc(ft_count_len(input) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (input[i])
	{
		if (quotes(input[i]))
			str[j++] = input[i];
		else if (input[i] != ' ' || (i > 0 && input[i - 1] != ' '))
			str[j++] = input[i];
		i++;
	}
	if (j > 0 && str[j - 1] == ' ')
		str[j - 1] = 0;
	return (str);
}
