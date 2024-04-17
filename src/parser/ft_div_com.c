/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:39:05 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 19:29:48 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	*failure(char *message)
{
	perror(message);
	return (NULL);
}

//Function gets how many characters are in the input param until c param
static int	ft_len_char(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!quotes(str[i]) && str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

//Function gets how many commands are in the input param
static int	get_len(const char *input)
{
	int	i;
	int	splits;

	i = 0;
	splits = 1;
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == '|')
			splits++;
		i++;
	}
	return (splits);
}

/* char *get_new_input(char const *input)
{
	char *result;

	result = 
	return ()	
}
 */

//Function gets all commands in a array of arrays
static char	**get_commands(const char *input)
{
	int		i;
	int		len;
	char	*input_cpy;
	char	*new_input;
	char	**commands;

	new_input = get_new_input(input);
	if (!new_input)
		return (NULL);
	i = 0;
	len = get_len(input);
	commands = (char **)malloc(len + 1 * sizeof(char *));
	if (!commands)
		return (NULL);
	input_cpy = (char *)input;
	while (i < len)
	{
		commands[i] = ft_substr(input_cpy, 0, ft_len_char(input_cpy, '|'));
		ft_strchr(input_cpy, '|');
		i++;
	}
	return (commands);
}


void	init_redir(t_redir *redirection)
{
	redirection->file_name = NULL;
	redirection->type = 0;	
}


void	fill_commands(char **commands, t_pipe *pipes)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		init_redir(&pipes->input);
		init_redir(&pipes->output);
		pipes[i].com = commands[i];
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
	int len;
	t_pipe *pipes;
	char **commands;
	len = 0;
	commands = get_commands(input);
	if (!commands)
		return (failure("malloc"));

	//TEST
	// int i = 0;
	// while(commands[i])
	// {
	// 	printf("Command #%d --> [%s]\n", i + 1, commands[i]);
	// 	i++;
	// }

	len = array_len((const char **)commands);

	pipes = (t_pipe *)malloc(len * sizeof(t_pipe));
	if (!pipes)
	{
		ft_free_array(commands);
		return (failure("malloc"));
	}
	fill_commands(commands, pipes);

	*com_len = len;
	return (NULL);
}
