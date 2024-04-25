/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/25 19:04:04 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_argv(char **argv, int i, int new_l)
{
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT);
		i++;
		if (argv[i])
			ft_putchar_fd(' ', STDOUT);
	}
	if (!new_l)
		ft_putchar_fd('\n', STDOUT);
}

int	check_flag(char **argv, int *i)
{
	int	j;
	int	flag;

	flag = 0;
	while (argv[*i])
	{
		j = 1;
		if (argv[*i][0] != '-')
			return (flag);
		while (argv[*i][j])
		{
			if (argv[*i][j] != 'n')
				return (flag);
			j++;
		}
		flag = 1;
		(*i)++;
	}
	return (flag);
}

void	ft_echo(char **argv, t_shell *data)
{
	int	i;
	int	flag;

	data->exit_code = EXIT_SUCCESS;
	if (!argv[1])
		return ((void)ft_putchar_fd('\n', STDOUT));
	i = 1;
	flag = check_flag(argv, &i);
	print_argv(argv, i, flag);
}
