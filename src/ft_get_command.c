/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/09 12:06:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_get_command(void)
{
	char	*command;
	char	*input;

	input = readline("minishell $> ");
	if (!input)
		return (NULL);
	command = ft_strtrim(input, " \n\t\v\f\r\b\a");
	free(input);
	if (*command)
	{
		add_history(command);
		printf("\"%s\" added to history\n", command);
	}
	return (command);
}
