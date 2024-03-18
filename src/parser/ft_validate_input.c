/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:58:44 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

short	ft_validate_input(char *com, char c)
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
		if (!quotes(com[i]) && com[i] == c && com[i + 1] == c && 
			(i > 0 && com[i - 1] == c))
		{
			printf("syntax error: unexpected token %c\n", c);
			return (1);
		}
		i++;
	}
	return (0);
}
