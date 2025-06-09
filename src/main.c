/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:52:41 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:48:26 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_shell(void) // Renamed and made static as it's only used here
{
	// Any shell initialization can go here
	// For example, loading history, setting up environment variables etc.
	// For now, it's empty.
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	(void)envp; // We will use envp later

	ft_init_shell();
	ft_init_signal_handlers();
	while (1)
	{
		if (g_signal_received == SIGINT)
		{
			// Potentially update exit status $? here if needed
			g_signal_received = 0;
		}
		line = readline(PROMPT);
		if (g_signal_received == SIGINT)
		{
			if (line)
				free(line);
			continue;
		}
		if (!line) // Ctrl-D was pressed (EOF)
		{
			printf("exit\n");
			break;
		}
		if (*line)
		{
			add_history(line);
			// Here will parse and execute the command
			printf("You entered: %s\n", line);
			t_list *tokens = ft_tokenize(line);
			if (tokens)
			{
				printf("Tokens generated (actual processing TBD).\n");
				ft_lstclear(&tokens, ft_free_token);
			}
		}
		free(line); // Free the memory allocated by readline
	}
	// rl_clear_history(); // Optional: clear history on exit
	return (0);
} 
