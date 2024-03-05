/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:34 by albartol          #+#    #+#             */
/*   Updated: 2023/10/06 13:10:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	dest_len;

	n = ft_strlen(dest);
	dest_len = n;
	i = 0;
	if (size == 0 || size <= dest_len)
		return (ft_strlen(src) + size);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (dest_len + ft_strlen(src));
}
