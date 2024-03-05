/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:11:53 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:12:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*cpy;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	str = (unsigned char *)dest;
	cpy = (unsigned char *)src;
	while (n--)
		str[n] = cpy[n];
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	bffer[10] = "123456789";

	ft_memmove(bffer + 4, &bffer[2], 3);
	printf("%s", bffer);
	return (0);
}  */
