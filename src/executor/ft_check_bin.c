/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:54:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:43:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_path(char *path, t_shell *data)
{
	size_t	i;
	size_t	j;
	size_t	len_com;
	size_t	len;
	char	*str;

	i = 0;
	len_com = ft_strlen(data->com->argv[0]);
	while (path[i] && path[i] != ':')
		i++;
	len = len_com + i + 1;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		ft_exit_program(data, "malloc");
	j = -1;
	while (++j < i)
		str[j] = path[j];
	str[j] = '/';
	i = 0;
	while (++j < len)
		str[j] = data->com->argv[0][i++];
	return (str);
}

static int	ft_len_path(char *path)
{
	int	len_path;

	len_path = 0;
	while (*path)
	{
		if (*path == ':')
			len_path++;
		path++;
	}
	return (len_path);
}

static char	*ft_check_path(char *path, t_shell *data)
{
	int		i;
	int		len_path;
	char	*str;

	i = 0;
	len_path = ft_len_path(path);
	str = 0;
	while (i < len_path && *path)
	{
		str = ft_get_path(path, data);
		if (access(str, X_OK) == 0)
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

char	*ft_check_bin(t_shell *data)
{
	char	*path;

	path = ft_get_env_value("PATH", data->env);
	if (!path)
		return (NULL);
	return (ft_check_path(path, data));
}
