/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:08:05 by albartol          #+#    #+#             */
/*   Updated: 2024/03/17 20:10:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	check_quotes(char *input)
{
	int		i;
	short	double_q;
	short	simple_q;

	i = 0;
	double_q = 0;
	simple_q = 0;
	while (input[i])
	{
		if (input[i] == '\"' && !simple_q)
			double_q ^= 1;
		else if (input[i] == '\'' && !double_q)
			simple_q ^= 1;
		i++;
	}
	return (double_q || simple_q);
}
