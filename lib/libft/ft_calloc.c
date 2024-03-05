/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:31:00 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:13:05 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*array;

	array = (void *)malloc(len * size);
	if (!array)
		return (0);
	ft_bzero(array, len * size);
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*a;

	a = (int *)ft_calloc(7, sizeof(int));
	printf("%p", a);
	free(a);
	return (0);
} */
