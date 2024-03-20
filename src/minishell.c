/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **env)
{
	t_shell	data;

	(void)argv;
	if (argc > 1)
		return (EXIT_SUCCESS);
	ft_minishell_init(&data, env);
	ft_minishell_loop(&data);
	// ft_lstclear(&data.env, free);
	free_program(&data);
	printf("Exiting minishell\n");
	return (data.exit_code);
}
