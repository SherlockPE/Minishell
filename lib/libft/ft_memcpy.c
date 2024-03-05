/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:21 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:12:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (dest);
	str = (unsigned char *)dest;
	temp = (unsigned char *)src;
	while (n > i)
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}
