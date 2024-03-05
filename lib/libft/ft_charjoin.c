/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:53:51 by albartol          #+#    #+#             */
/*   Updated: 2024/01/12 18:06:50 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *str, char c)
{
	char	temp[2];
	char	*aux;

	temp[0] = c;
	temp[1] = 0;
	aux = ft_strjoin(str, temp);
	if (!aux)
		return (NULL);
	return (aux);
}
