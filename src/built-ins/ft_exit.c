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
	ft_putstr_fd("exit: [", 2);
	ft_putstr_fd(num, 2);
	ft_putstr_fd("]: numeric argument required\n", 2);
	// printf("exit: [%s]: numeric argument required\n", num);
	return (0);
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
	return (1);
}

void	ft_exit(t_shell *data)
{
	if (data->com->argv[1] && data->com->argv[2])
		ft_putstr_fd("exit: too many arguments\n", 2);
	else
	{
		if (data->com->argv[1])
		{
			check_num(data->com->argv[1]);
			data->exit_code = ft_atol(data->com->argv[1]);
		}
		free_program(data);
		exit(data->exit_code);
	}
}
