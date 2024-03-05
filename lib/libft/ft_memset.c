/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:54:22 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:12:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)dest;
	while (n > i)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	char	string1[10];
	char	bffer;

	bffer = 'R';
	ft_memset(string1, bffer, 9);
	printf("%s", string1);
	return (0);
} */
