/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:01:12 by albartol          #+#    #+#             */
/*   Updated: 2024/03/05 18:47:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	int			i;
	long long	nbr;
	int			sym;

	i = 0;
	nbr = 0;
	sym = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sym = -sym;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr *= sym;
	return (nbr);
}
