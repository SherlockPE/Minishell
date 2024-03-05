/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:26:02 by albartol          #+#    #+#             */
/*   Updated: 2023/09/29 15:04:01 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((unsigned char)c == 0)
		return ((char *)&str[i]);
	while (i--)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
	}
	return (0);
}
