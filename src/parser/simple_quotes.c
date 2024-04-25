/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:49:08 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:14:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	simple_quotes(const char c, const char reset)
{
	static short	simple_q;
	static short	double_q;

	if (reset)
	{
		simple_q = 0;
		double_q = 0;
		return (0);
	}
	if (c == '\'' && !double_q)
		simple_q ^= 1;
	else if (c == '\"' && !simple_q)
		double_q ^= 1;
	return (simple_q);
}
