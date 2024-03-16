/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:10:21 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 17:12:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*array_to_str(char **array, char spliter)
{
	char	*str;
	char	split[2];
	size_t	len;
	int		splits;
	int		i;

	i = 0;
	if (spliter)
	{
		split[0] = spliter;
		split[1] = 0;
		splits = array_len(array);
	}
	else
		splits = 0;
	len = array_char_len(array) + splits;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while(array[i])
	{
		ft_strlcat(str, array[i], len + 1);
		i++;
		if (spliter && array[i])
			ft_strlcat(str, split, len + 1);
	}
	return (str);
}
