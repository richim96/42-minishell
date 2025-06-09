/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:00:00 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:49:52 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Finds the matching closing quote.
 * @param input	(const char *) The input string.
 * @param quote	(char) The opening quote character.
 * @return The length of the quoted string (including quotes), or 0 if no matching quote.
 */
static size_t	ft_find_quote_end(const char *input, char quote)
{
	size_t	len;

	len = 1; // Skip opening quote
	while (input[len] && input[len] != quote)
		len++;
	if (!input[len]) // No matching quote found
		return (0);
	return (len + 1); // Include closing quote
}

/**
 * @brief Checks if a character is a quote.
 * @param c	(char) The character to check.
 * @return 1 if the character is a quote, 0 otherwise.
 */
int	ft_isquote(char c)
{
	return (c == '\'' || c == '"');
}

/**
 * @brief Handles a quoted string in the input.
 * @param current_char	(const char **) Pointer to current position in input.
 * @param tokens	(t_list **) Pointer to token list.
 * @return 1 on success, 0 on failure.
 */
int	ft_handle_quotes(const char **current_char, t_list **tokens)
{
	char		quote;
	size_t		len;
	t_token_type	type;

	quote = **current_char;
	type = SINGLE_QUOTE;
    if (quote == '"')
        type = DOUBLE_QUOTE;
	len = ft_find_quote_end(*current_char, quote);
	if (len == 0)
	{
		// TODO: Handle error - unclosed quote
		return (0);
	}
	if (!ft_add_token(tokens, type, *current_char, len))
		return (0);
	*current_char += len;
	return (1);
} 
