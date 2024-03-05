/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:33:54 by albartol          #+#    #+#             */
/*   Updated: 2023/10/03 16:19:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
		n++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			n++;
		i++;
	}
	return (n);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_free_split(char **array, int nb)
{
	while (nb >= 0)
		free(array[nb--]);
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	int		nb;
	char	**array;

	i = ft_count_split(s, c);
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (0);
	n = 0;
	nb = 0;
	while (i--)
	{
		while (s[n] == c && s[n])
			n++;
		array[nb] = ft_substr(s, n, ft_word_len(s + n, c));
		if (!array[nb++])
			return (ft_free_split(array, --nb));
		while (s[n] != c && s[n])
			n++;
	}
	array[nb] = 0;
	return (array);
}

/* #include <stdio.h>

int	main(void)
{
  int i = 0;
  char **array = ft_split("lorem  ipsum  dolor  sit  amet", ' ');
	while (array[i])
		printf("%s\n", array[i++]);
	printf("%s\n", ft_split("       ", ' '));
	return (0);
} */