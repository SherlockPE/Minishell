/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/27 15:53:39 by albartol         ###   ########.fr       */
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
		else if (!ft_strchr(NOT_VAL, input[i])
			|| (i > 0 && !ft_strchr(NOT_VAL, input[i - 1])))
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
		else if (!ft_strchr(NOT_VAL, input[i])
			|| (i > 0 && !ft_strchr(NOT_VAL, input[i - 1])))
			str[j++] = input[i];
		i++;
	}
	if (j > 0 && ft_strchr(NOT_VAL, str[j - 1]))
		str[j - 1] = 0;
	return (str);
}
