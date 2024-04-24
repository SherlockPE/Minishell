/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:39:05 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 18:12:54 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//Function gets all commands in a array of arrays
static char	**get_commands(const char *input)
{
	char	*new_input;
	char	**commands;

	new_input = trim_input(input);
	if (!new_input)
		return (NULL);
	commands = ft_split_quotes(new_input, '|');
	free(new_input);
	if (!commands)
		return (NULL);
	return (commands);
}

static void	init_redir(t_redir *redirection)
{
	redirection->file_name = 0;
	redirection->type = 0;
}

static void	fill_commands(char **commands, t_pipe *pipes)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		init_redir(&pipes[i].input);
		init_redir(&pipes[i].output);
		pipes[i].com = commands[i];
		pipes[i].argv = 0;
		i++;
	}
}

// La funcion va a cojer el string entero 
// y va a dividir el input en pipes
// guardando todo en la posicion/nodo del array
// data->com  (t_pipe *)
// data->com_len need to be initialized here
t_pipe	*ft_div_com(const char *input, int *com_len)
{
	int		len;
	t_pipe	*pipes;
	char	**commands;

	len = 0;
	commands = get_commands(input);
	if (!commands)
		return (NULL);
	len = array_len((const char **)commands);
	pipes = (t_pipe *)malloc(len * sizeof(t_pipe));
	if (!pipes)
	{
		ft_free_array(commands);
		return (NULL);
	}
	fill_commands(commands, pipes);
	*com_len = len;
	free(commands);
	return (pipes);
}
