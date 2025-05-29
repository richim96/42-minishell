#ifndef MINISHELL_H
# define MINISHELL_H

// Standard Libraries
# include <stdio.h>      // For printf, perror
# include <stdlib.h>     // For malloc, free, exit, getenv
# include <unistd.h>     // For access, fork, pipe, execve, dup, dup2, close, getcwd, chdir, unlink
# include <string.h>     // For strerror
# include <sys/wait.h>   // For wait, waitpid, wait3, wait4
# include <sys/stat.h>   // For stat, lstat, fstat
# include <sys/ioctl.h>  // For ioctl (not explicitly listed, but often useful for terminal info)
# include <fcntl.h>      // For open, read, write
# include <signal.h>     // For signal, sigaction, sigemptyset, sigaddset, kill
# include <dirent.h>    // For opendir, readdir, closedir
# include <termios.h>    // For tcsetattr, tcgetattr
# include <term.h>      // For tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs (part of termcap, often with readline)

// Readline library
# include <readline/readline.h>
# include <readline/history.h>

// Custom includes
# include "../src/lib/libft/include/libft.h" 

// Project-specific defines
# define PROMPT "minishell> "

// Global variable for signal handling (as per requirements, max one for signal number)
extern volatile sig_atomic_t g_signal_received;

// Function Prototypes (will be expanded as we build)

// Signal handling functions
void ft_setup_signal_handlers(void);

#endif 
