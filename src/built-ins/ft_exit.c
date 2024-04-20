/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/20 16:12:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	invalid_argv(const char *num)
{
	ft_putstr_fd("exit: [", STDERR);
	ft_putstr_fd(num, STDERR);
	ft_putstr_fd("]: numeric argument required\n", STDERR);
	// printf("exit: [%s]: numeric argument required\n", num);
	return (EXIT_FAILURE);
}

static int	check_num(const char *num)
{
	int	i;

	i = 0;
	while (num[i] && num[i + 1])
	{
		if (!ft_isdigit(num[i]) && !(num[i] == '-' || num[i] == '+'))
			return (invalid_argv(num));
		if (!ft_isdigit(num[i]) && ((num[i] == '-' || num[i] == '+')
				&& !ft_isdigit(num[i + 1])))
			return (invalid_argv(num));
		if (!ft_isdigit(num[i]) && i > 0 && ft_isdigit(num[i - 1]))
			return (invalid_argv(num));
		i++;
	}
	if (!ft_isdigit(num[i]))
		return (invalid_argv(num));
	if (i > 20 || (ft_atoll(num) > LONG_MAX || ft_atoll(num) < LONG_MIN))
		return (invalid_argv(num));
	return (EXIT_SUCCESS);
}

void	ft_exit(char **argv, t_shell *data)
{
	ft_putstr_fd("exit\n", STDOUT);
	if (argv[1] && argv[2])
	{
		data->exit_code = EXIT_FAILURE;
		ft_putstr_fd("exit: too many arguments\n", STDERR);
	}
	else
	{
		if (argv[1])
		{
			if (check_num(argv[1]))
				data->exit_code = EXIT_NUM;
			else
				data->exit_code = ft_atol(argv[1]);
		}
		free_program(data);
		ft_free_array(argv);
		exit(data->exit_code);
	}
}
