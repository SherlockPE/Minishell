/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:34:22 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 21:29:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_rm_quotes(const char **argv)
{
	int		i;
	size_t	len;
	char	**new_argv;

	i = 0;
	len = array_len(argv);
	new_argv = ft_calloc(len + 1, sizeof(char *));
	if (!new_argv)
		return (NULL);
	// while (argv[i])
	// {
	// 	printf("argv %d --> [%s]\n", i, argv[i]);
	// 	i++; 
	// }
	i = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '\"') || ft_strchr(argv[i], '\''))
			new_argv[i] = ft_trim_quotes(argv[i]);
		else
			new_argv[i] = ft_strdup(argv[i]);
		if (!new_argv[i])
		{
			ft_free_array(new_argv);
			return (NULL);
		}
		i++;
	}
	return (new_argv);
}
