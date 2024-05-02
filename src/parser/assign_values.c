/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:43:21 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 15:38:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_value(const char *input, char *value, short quote)
{
	if (!quote && ft_strchr(NOT_VAL, *input))
		*value = BLANK;
	else if (!quote && *input == '|')
		*value = PIPE;
	else if (!quote && *input == '<')
		*value = I_REDIR;
	else if (!quote && *input == '>')
		*value = O_REDIR;
	else
		*value = TEXT;
}

static void	fill_value(const char *input, char *value, size_t i, size_t len)
{
	short	quote;
	short	simple_q;
	short	double_q;

	while (i < len)
	{
		simple_q = simple_quotes(input[i]);
		double_q = double_quotes(input[i]);
		quote = quotes(input[i]);
		if ((simple_q || !quote) && input[i] == '\'')
			value[i] = S_QUOTE;
		else if ((double_q || !quote) && input[i] == '\"')
			value[i] = D_QUOTE;
		else if (!simple_q && input[i] == '$')
			value[i] = EXPAND;
		else
			set_value(&input[i], &value[i], quote);
		i++;
	}
}

char	*assign_values(const char *input)
{
	size_t	i;
	size_t	len;
	char	*value;

	len = ft_strlen(input);
	value = (char *)ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (NULL);
	i = 0;
	fill_value(input, value, i, len);
	while (i < len)
		printf("%d", value[i++]);
	printf("\n");
	return (value);
}
