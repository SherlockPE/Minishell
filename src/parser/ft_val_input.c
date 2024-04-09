/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/09 20:16:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	ft_val_input(const char *com, const char c, const char b)
{
	int		i;

	if (!com || !*com)
		return (1);
	if ((com[0] == c && c != '<') || com[ft_strlen(com) - 1] == c 
		|| (com[0] == b && b != '<') || com[ft_strlen(com) - 1] == b)
	{
		printf("syntax error: unexpected token %c\n", c);
		return (1);
	}
	i = 0;
	while (com[i])
	{
		if (!quotes(com[i]))
		{
			if (com[i] == c && com[i + 1] == c && (i > 0 && com[i - 1] == c) 
				&& (com[i + 1] == b || (i > 0 && com[i - 1] == b)))
			{
				printf("syntax error: unexpected token %c\n", c);
				return (1);
			}
			if (com[i] == b && com[i + 1] == b && (i > 0 && com[i - 1] == b) 
				&& (com[i + 1] == c || (i > 0 && com[i - 1] == c)))
			{
				printf("syntax error: unexpected token %c\n", c);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
