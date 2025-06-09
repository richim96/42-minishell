/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:12:41 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:53:37 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stddef.h>
#include "../lib/libft/include/libft.h"

/**
 * @brief Valid token types for the minishell lexer.
 * @param WORD (char *) e.g., command, argument, filename
 * @param PIPE (char *) |
 * @param REDIRECT_IN (char *) <
 * @param REDIRECT_OUT (char *) >
 * @param HEREDOC (char *) <<
 * @param APPEND_OUT (char *) >>
 * @param SINGLE_QUOTE (char *) '...'
 * @param DOUBLE_QUOTE (char *) "..."
 * @param STRING_LITERAL (char *) "hello" or 'world'
 * @param ENV_VAR (char *) $VAR or $?
 * @param LOGICAL_AND (char *) &&
 * @param LOGICAL_OR (char *) ||
 * @param LPARENTHESIS (char *) (
 * @param RPARENTHESIS (char *) )
 */
typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
	APPEND_OUT,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
    STRING_LITERAL,
	ENV_VAR,
	LOGICAL_AND,
	LOGICAL_OR,
	LPARENTHESIS,
	RPARENTHESIS,
	WILDCARD,
	WHITESPACE,
	END_OF_FILE,
	ERROR
}   t_token_type;

/**
 * @brief A token.
 * @param value (char) Actual value of the token, e.g., "ls", "|", "file.txt"
 * @param type  (t_token_type) Pre-defined token type
 * @param len   (size_t) The length of the token value
 */
typedef struct s_token
{
	char		    *value;
	t_token_type	type;
	size_t			len;
}   t_token;

// Function prototypes
// Lexer

t_list  		*ft_tokenize(const char *input_line);

// Tokens

int				ft_add_token(
					t_list **head,
					t_token_type type,
					const char *value,
					size_t len);
void    		ft_free_token(void *token_ptr); // For ft_lstclear

// Operators

int				ft_isoperator(char c);
t_token_type	ft_operator_type(char c, char next);
size_t			ft_operator_len(char c, char next);

// Quotes

int				ft_isquote(char c);
int				ft_handle_quotes(const char **current_char, t_list **tokens);

#endif
