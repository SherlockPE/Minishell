/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:24 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:11:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		while (str1[i + n] == str2[n] && str1[i + n] && (i + n) < len)
			n++;
		if (str2[n] == '\0')
			return ((char *)str1 + i);
		i++;
		n = 0;
	}
	return (0);
}
