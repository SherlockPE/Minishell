/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:54:54 by albartol          #+#    #+#             */
/*   Updated: 2024/03/29 15:22:24 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	count_len(char *str)
{
	int	i;
	int	len;
	int	len_quotes;

	i = 0;
	len = 0;
	len_quotes = 0;
	while (str[i])
	{
		if (!quotes(str[i]))
			len++;
		else
			len_quotes++;
		i++;
		if (!quotes(str[i]) && len_quotes)
			len = len + len_quotes - 2;
	}
	return (len);
}

static void	fill_new_str(char *new_str, char *str)
{
	int	i;
	int	j;
	int	len_quotes;

	i = 0;
	j = 0;
	len_quotes = 0;
	while (str[i])
	{
		if (!quotes(str[i]))
			new_str[j++] = str[i];
		else
		{
			if (!len_quotes)
				len_quotes = 1;
			else
				new_str[j++] = str[i];
		}
		i++;
		if (!quotes(str[i]) && len_quotes)
		{
			j--;
			len_quotes = 0;
		}
	}
}

char	*ft_trim_quotes(char *str)
{
	int		len;
	char	*new_str;

	len = count_len(str);
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	fill_new_str(new_str, str);
	return (new_str);
}
