/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:49:08 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 17:18:32 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	simple_quotes(const char c)
{
	static short	simple_q;
	static short	double_q;

	if (c == '\'' && !double_q)
		simple_q ^= 1;
	else if (c == '\"' && !simple_q)
		double_q ^= 1;
	return (simple_q);
}
