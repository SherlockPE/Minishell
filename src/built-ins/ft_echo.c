/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/28 18:03:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_argv(char **argv, int i)
{
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		i++;
		if (argv[i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
}

void	ft_echo(char **argv)
{
	int	i;

	if (!argv[1])
		return ((void)ft_putchar_fd('\n', STDOUT_FILENO));
	i = 1;
	if (!ft_strncmp(argv[1], "-n", 2))
	{
		i = 2;
		print_argv(argv, i);
		return ;
	}
	print_argv(argv, i);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
