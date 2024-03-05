/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:58:19 by albartol          #+#    #+#             */
/*   Updated: 2023/09/29 15:05:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	len;

	i = ft_strlen(s1);
	n = ft_strlen(s2);
	len = i + n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	len = 0;
	while (len < i)
	{
		str[len] = s1[len];
		len++;
	}
	len = 0;
	while (len < n)
	{
		str[i + len] = s2[len];
		len++;
	}
	str[i + len] = 0;
	return (str);
}

/* #include <stdio.h>

int main () {
   char *a = "megalovanina";
   char *b = "piña";
   char *join = ft_strjoin(a,b);

   printf("%s\n", a);
   printf("%s\n", b);
   printf("%s\n", join);
   free(join);
   return(0);
} */