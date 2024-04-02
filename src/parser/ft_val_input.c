/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/02 16:58:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	ft_val_input(const char *com, const char c)
{
	int		i;

	if (!com || !*com)
		return (1);
	if (com[0] == c || com[ft_strlen(com) - 1] == c)
	{
		printf("syntax error: unexpected token %c\n", c);
		return (1);
	}
	i = 0;
	while (com[i])
	{
		if (!quotes(com[i]) && com[i] == c && com[i + 1] == c
			&& (i > 0 && com[i - 1] == c))
		{
			printf("syntax error: unexpected token %c\n", c);
			return (1);
		}
		i++;
	}
	return (0);
}
