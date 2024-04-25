/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/25 16:04:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_argv(char **argv, int i)
{
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT);
		i++;
		if (argv[i])
			ft_putchar_fd(' ', STDOUT);
	}
}

void	ft_echo(char **argv, t_shell *data)
{
	int	i;

	if (!argv[1])
		return ((void)ft_putchar_fd('\n', STDOUT));
	i = 1;
	if (!ft_strncmp(argv[1], "-n\0", 3))
	{
		i = 2;
		print_argv(argv, i);
		return (ft_set_exit(data, EXIT_SUCCESS));
	}
	print_argv(argv, i);
	ft_putchar_fd('\n', STDOUT);
}
