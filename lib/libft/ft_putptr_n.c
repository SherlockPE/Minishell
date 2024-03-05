/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:32:24 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:11:01 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_n(unsigned long ptr)
{
	int	res;
	int	n;

	res = write(1, "0x", 2);
	if (res == -1)
		return (-1);
	n = ft_putnbr_base_n(ptr, "0123456789abcdef");
	if (n == -1)
		return (-1);
	res += n;
	return (res);
}
