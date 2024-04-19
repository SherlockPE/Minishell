/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/04/19 15:26:05 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	export_val(const char *value, t_shell *data)
{
	int	i;

	i = 0;
	while (value[i] && value[i] != '=')
	{
		if (!ft_isalnum(value[i]) && value[i] != '_')
		{
			ft_putstr_fd("export: \'", STDERR);
			ft_putstr_fd(value, STDERR);
			ft_putstr_fd("\': not a valid identifier\n", STDERR);
			data->exit_code = EXIT_FAILURE;
			return ;
		}
		i++;
	}
	if ((i == 0 && value[i] == '=') || (value[i] != '='))
	{
		ft_putstr_fd("export: \'", STDERR);
		ft_putstr_fd(value, STDERR);
		ft_putstr_fd("\': not a valid identifier\n", STDERR);
		data->exit_code = EXIT_FAILURE;
		return ;
	}
	else if (value[i] == '=')
		ft_set_env_value(value, data);
}

void	ft_export(char **argv, t_shell *data)
{
	int	i;

	if (!argv[1])
		return (ft_env(argv, data));
	i = 1;
	while (argv[i])
	{
		export_val(argv[i], data);
		i++;
	}
}
