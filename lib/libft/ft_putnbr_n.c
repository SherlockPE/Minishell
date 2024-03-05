/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:54:06 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:10:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_n(long nbr)
{
	int	res;
	int	i;

	res = 0;
	if (nbr < 0)
	{
		i = ft_putchar_n('-');
		if (i == -1)
			return (-1);
		res += i;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		i = ft_putnbr_n(nbr / 10);
		if (i == -1)
			return (-1);
		res += i;
	}
	i = ft_putchar_n(nbr % 10 + 48);
	if (i == -1)
		return (-1);
	res += i;
	return (res);
}
