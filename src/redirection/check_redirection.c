/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:12:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/28 14:01:47 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// //-1 does not found a '>'
// void   	check_redirection(t_shell *data)
// {
// 	int i;
// 	int status;

// 	i = 0;
// 	status = 0;
// 	while (data->input[i])
// 	{
// 		if (data->input[i] == '>')
// 			status++;
// 		i++;
// 	}
// 	if (status > 2)
// 	{
// 		printf("syntax error near unexpected token `>'");
// 		return (free_input(data));
// 	}
// 	data->redir = status;
// }