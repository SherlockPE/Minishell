/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:54:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 18:43:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_path(char *path, char *bin)
{
	size_t	i;
	size_t	j;
	size_t	len_com;
	size_t	len;
	char	*str;

	i = 0;
	len_com = ft_strlen(bin);
	while (path[i] && path[i] != ':')
		i++;
	len = len_com + i + 1;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		perror("malloc");
		return (NULL);
	}
	j = -1;
	while (++j < i)
		str[j] = path[j];
	str[j] = '/';
	i = 0;
	while (++j < len)
		str[j] = bin[i++];
	return (str);
}

static int	ft_len_path(char *path)
{
	int	len_path;

	len_path = 1;
	while (*path)
	{
		if (*path == ':')
			len_path++;
		path++;
	}
	return (len_path);
}

static char	*ft_check_path(char *path, char *bin)
{
	int		i;
	int		len_path;
	char	*str;

	i = 0;
	len_path = ft_len_path(path);
	str = 0;
	while (i < len_path && *path)
	{
		str = ft_get_path(path, bin);
		if (!str)
			return (NULL);
		if (access(str, F_OK) == 0)
			break ;
		free(str);
		str = 0;
		i++;
		while (*path && *path != ':')
			path++;
		if (*path == ':')
			path++;
	}
	return (str);
}

char	*ft_check_bin(char *bin, char *path)
{
	char	*bin_path;

	if (!path || !bin || !*bin)
		return (NULL);
	bin_path = ft_check_path(path, bin);
	if (!bin_path)
		return (NULL);
	return (bin_path);
}
