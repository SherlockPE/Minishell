/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:43:21 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 16:08:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_validate_input(const char *input)
{
	if (check_quotes(input))
	{
		ft_putstr_fd("syntax_error: unexpected end of file\n", STDERR);
		return (1);
	}
	if (check_pipes(input))
		return (1);
	if (check_forbidden(input))
		return (1);
	return (0);
}