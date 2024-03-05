/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:21:43 by albartol          #+#    #+#             */
/*   Updated: 2023/11/20 17:11:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (0);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
   char *a = "megalovanina";
   char *dup1 = strdup(a);
   char *dup2 = ft_strdup(a);

   printf("%s\n", a);
   printf("%s\n", dup1);
   free(dup1);
   printf("%s\n", dup2);
   free(dup2);
   return(0);
} */
