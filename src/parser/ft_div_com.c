/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:39:05 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 15:50:35 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	no_pipe_len(const char *value)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(value);
	while (value[i])
	{
		if (value[i] == PIPE)
		{
			if (value[i + 1] == BLANK)
				len--;
			if (i > 0 && value[i - 1] == BLANK)
				len--;
		}
		i++;
	}
	return (len);
}

static char	*rm_pipe_spaces(const char *input, const char *value)
{
	int		i;
	int		j;
	char	*result;

	result = (char *)ft_calloc(no_pipe_len(input), sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (value[++i])
	{
		result[j] = input[i];
		if (value[i] == PIPE)
		{
			if (i > 0 && value[i - 1] == BLANK)
			{
				j--;
				result[j] = input[i];
			}
			if (value[i + 1] == BLANK)
				i++;
		}
		j++;
	}
	return (result);
}

//Function gets all commands in a array of arrays
static char	**get_commands(t_input *input)
{
	t_input	new_input;
	char	*temp;
	char	**commands;

	new_input.str = trim_input(input);
	if (!new_input.str)
		return (NULL);
	new_input.value = assign_values(new_input.str);
	if (!new_input.value)
	{
		free(new_input.str);
		return (NULL);
	}
	temp = rm_pipe_spaces(new_input.str, new_input.value);
	free(new_input.str);
	free(new_input.value);
	if (!temp)
		return (NULL);
	new_input.str = temp;
	new_input.value = assign_values(new_input.str);
	if (!new_input.value)
	{
		free(new_input.str);
		return (NULL);
	}
	commands = ft_split_value(&new_input, PIPE);
	free(new_input.str);
	free(new_input.value);
	return (commands);
}

// static void	init_redir(t_redir *redirection)
// {
// 	redirection->file_name = 0;
// 	redirection->type = 0;
// }

static void	fill_commands(char **commands, t_pipe *pipes)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		printf("div %i: [%s]\n", i, commands[i]);
		pipes[i].com.str = commands[i];
		pipes[i].com.value = 0;
		pipes[i].com.read_pos = 0;
		pipes[i].com.peek_pos = 0;
		pipes[i].redir = 0;
		pipes[i].redir_num = 0;
		// init_redir(&pipes[i].input);
		// init_redir(&pipes[i].output);
		pipes[i].argv = 0;
		i++;
	}
}

// La funcion va a cojer el string entero 
// y va a dividir el input en pipes
// guardando todo en la posicion/nodo del array
// data->com  (t_pipe *)
// data->com_len need to be initialized here
t_pipe	*ft_div_com(t_input *input, int *com_len)
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
