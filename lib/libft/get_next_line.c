/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:30:37 by albartol          #+#    #+#             */
/*   Updated: 2023/12/22 13:46:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_order_nl(char *str)
{
	char	*res;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), str = NULL, NULL);
	res = (char *)ft_calloc(ft_strlen(str) - i + 1, 1);
	if (!res)
		return (free(str), str = NULL, NULL);
	i++;
	while (str[i])
		res[n++] = str[i++];
	return (free(str), res);
}

static char	*ft_substr_nl(char *str)
{
	char	*res;
	int		i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		res = (char *)ft_calloc(i + 1, 1);
	else
		res = (char *)ft_calloc(i + 2, 1);
	if (!res)
		return (0);
	while (i >= 0)
	{
		res[i] = str[i];
		i--;
	}
	return (res);
}

static char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	len;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, 1);
		if (!s1)
			return (0);
	}
	if (!s2)
		return (free(s1), NULL);
	i = ft_strlen(s1);
	n = ft_strlen(s2);
	str = (char *)ft_calloc(i + n + 1, 1);
	if (!str)
		return (free(s1), NULL);
	len = -1;
	while (++len < i)
		str[len] = s1[len];
	len = -1;
	while (++len < n)
		str[i + len] = s2[len];
	return (free(s1), str);
}

static char	*ft_read_nl(char *str, int fd)
{
	char	*res;
	ssize_t	data;

	res = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res)
		return (free(str), NULL);
	data = 2;
	while (!(ft_strchr(str, '\n')) && data)
	{
		data = read(fd, res, BUFFER_SIZE);
		if (data == -1)
			return (free(res), free(str), NULL);
		if (data == 0)
			return (free(res), str);
		res[data] = 0;
		str = ft_strjoin_nl(str, res);
		if (!str)
			return (free(res), str);
	}
	return (free(res), str);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	temp[fd] = ft_read_nl(temp[fd], fd);
	if (!temp[fd])
		return (0);
	res = ft_substr_nl(temp[fd]);
	if (!res)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	temp[fd] = ft_order_nl(temp[fd]);
	return (res);
}

/* int	main(int argc, char **argv)
{
	int i = 50;
	int fd = open(argv[argc], O_RDONLY);
	char *res;
	while (i-- && --argc)
	{
		res = get_next_line(fd);
		printf("%s", res);
		if (res)
			free (res);
		fd = open(argv[argc], O_RDONLY);
	}
	return (0);
} */