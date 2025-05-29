#include "minishell.h"

// This comment can be removed as g_signal_received is defined in signals.c

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
	ft_setup_signal_handlers(); // Call the renamed signal setup function
	// rl_catch_signals = 0; // Set this to 0 if you want to handle signals entirely manually
							 // Readline's default SIGINT handler might conflict or be redundant

	while (1)
	{
		// Reset signal flag before reading new input
		if (g_signal_received == SIGINT)
		{
			// Potentially update exit status $? here if needed
			g_signal_received = 0; // Reset the flag
		}

		line = readline(PROMPT);

		// Check if readline was interrupted by our SIGINT handler
		// and g_signal_received was set. If so, readline might return NULL
		// or the line it was processing. We already handled the display
		// in the signal handler itself.
		if (g_signal_received == SIGINT) // Check flag again after readline
		{
			if (line) free(line); // Free if readline returned something despite interrupt
			continue; // Loop back to get fresh prompt and input
		}

		if (!line) // Ctrl-D was pressed (EOF)
		{
			printf("exit\n"); // Mimic bash behavior
			break;
		}

		if (*line) // If the line is not empty
		{
			add_history(line);
			// Here we will parse and execute the command
			// For now, let's just print it back
			printf("You entered: %s\n", line);
		}
		free(line); // Free the memory allocated by readline
	}

	// rl_clear_history(); // Optional: clear history on exit
	return (0);
} 
