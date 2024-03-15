/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:38:28 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/15 12:46:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>

// void	ft_echo(t_shell *data, const char *command)
// {
// 	char	*print;
// 	int		i;

// 	i = 0;
// 	print = ft_strtrim(command, " \"\t");
// 	printf("The command is[%s]\n", print);
// 	if (ft_strnstr(print, "-n", 2))
// 	{
// 		printf("The command is[%s]\n", print + 2);
// 		if (*(print + 2) == ' ')
// 			printf("%s", print + 3);
// 		else
// 			printf("%s\n", print);
// 	}
// 	else
// 		printf("%s\n", print);
// 	free(print);
// }
