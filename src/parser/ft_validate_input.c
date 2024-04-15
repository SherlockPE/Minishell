/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:43:21 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int syntax_error(const char *message)
{
	char *print;

	print = ft_strjoin("syntax_error: ", message);
	if (!print)
		perror("malloc");
	else
		ft_putstr_fd(print, STDERR);
	return (1);
}

static int check_last(const char *input, const char *set)
{
	size_t len;

	len = ft_strlen(input);
	if (len > 0)
		len--;
	while ( len > 0 && input[len] == ' ')
		len--;
	if (ft_strchr(set, input[len]))
		return (syntax_error("unexpected end of file\n"));
	return (0);
}

static int check_pipes(const char *input)
{
	int	i;
	int	pipe;

	i = 0;
	pipe = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (syntax_error("unexpected token \'|\'\n"));
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == '|')
		{
			pipe ^= 1;
			i++;
			while (input[i] == ' ')
				i++;
			if (!input[i])
				break ;
		}
		if (!quotes(input[i]) /* && pipe */ && input[i] == '|')
			return (syntax_error("unexpected token \'|\'\n"));
		i++;
	}
	return (check_last(input, "|"));
}

static int check_redir(const char *input)
{
	int	i;
	int	redir;

	i = 0;
	redir = 0;
	while (input[i])
	{
		if (!quotes(input[i]) && ft_strchr("<>", input[i]))
		{
			redir ^= 1;
			printf("--> [%i]\n", redir);
			i++;
			if (input[i] == input[i - 1])
				i++;
			while (input[i] == ' ')
				i++;
			if (!input[i])
				break ;
		}
		if (!quotes(input[i]) /* && redir */ && ft_strchr("<>", input[i]))
			return (syntax_error("unexpected token\n"));
		i++;
	}
	return (check_last(input, "<>"));
}

int	ft_validate_input(const char *input)
{
	if (ft_strlen(input) == 0)
		return (1);
	if (check_quotes(input))
		return (syntax_error("unexpected end of file\n"));
	if (check_pipes(input))
		return (1);
	if (check_redir(input))
		return (1);
	return (0);
}
