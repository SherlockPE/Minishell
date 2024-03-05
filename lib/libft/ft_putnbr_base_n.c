/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:53:33 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:10:55 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print(unsigned long nbr, unsigned int base_len, char *base)
{
	char	result;
	int		res;
	int		n;

	res = 0;
	result = base[nbr % base_len];
	if (nbr >= base_len)
	{
		res = ft_print(nbr / base_len, base_len, base);
		if (res == -1)
			return (-1);
	}
	n = write(1, &result, 1);
	if (n == -1)
		return (-1);
	res += n;
	return (res);
}

int	ft_putnbr_base_n(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	i;

	base_len = 0;
	i = base_len + 1;
	while (base[base_len])
	{
		if (base[base_len] < 32 || base[base_len] > 126)
			return (0);
		if (base[base_len] == 43 || base[base_len] == 45)
			return (0);
		while (base[i])
		{
			if (base[base_len] == base[i])
				return (0);
			i++;
		}
		base_len++;
		i = base_len + 1;
	}
	if (base_len <= 1)
		return (0);
	return (ft_print(nbr, base_len, base));
}
