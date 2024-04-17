/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:33:53 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 16:33:55 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**array_dup(const char **array)
{
	char	**copy;
	int		len;
	int		i;

	len = array_len(array);
	copy = ft_calloc(len + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			ft_free_array(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}
