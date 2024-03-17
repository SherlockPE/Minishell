/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:58:05 by albartol          #+#    #+#             */
/*   Updated: 2024/03/17 21:10:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	quotes(char c)
{
	static short	double_q;
	static short	simple_q;

	if (c == '\"' && !simple_q)
		double_q ^= 1;
	else if (c == '\'' && !double_q)
		simple_q ^= 1;
	if (double_q || simple_q)
		return (1);
	return (0);
}
