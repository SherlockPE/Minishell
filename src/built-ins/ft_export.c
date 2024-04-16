/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:10:51 by albartol          #+#    #+#             */
/*   Updated: 2024/04/10 15:31:21 by albartol         ###   ########.fr       */
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
			ft_putstr_fd("\': is not a valid identifier\n", STDERR);
			return ;
		}
		i++;
	}
	if (i == 0 && value[i] == '=')
	{
		ft_putstr_fd("export: \'", STDERR);
		ft_putstr_fd(value, STDERR);
		ft_putstr_fd("\': is not a valid identifier\n", STDERR);
		return ;
	}
	else if (value[i] == '=')
		ft_set_env_value(value, data);
}

void	ft_export(char **argv, t_shell *data)
{
	int	i;

	if (!data->com->argv[1])
		return (ft_env(argv, data));
	i = 1;
	while (data->com->argv[i])
	{
		export_val(argv[i], data);
		i++;
	}
}
