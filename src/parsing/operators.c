/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:08:53 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:54:25 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

/**
 * @brief Checks if a character is an operator.
 * @param c	(char) The character to check.
 * @return 1 if the character is an operator, 0 otherwise.
 */
int	ft_isoperator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

/**
 * @brief Gets the token type for an operator.
 * @param c	    (char) The operator character.
 * @param next	(char) The next character.
 * @return The token type for the operator.
 */
t_token_type	ft_operator_type(char c, char next)
{
	if (c == '|')
		return (PIPE);
	if (c == '<')
	{
		if (next == '<')
			return (HEREDOC);
		return (REDIRECT_IN);
	}
	if (c == '>')
	{
		if (next == '>')
			return (APPEND_OUT);
		return (REDIRECT_OUT);
	}
	return (ERROR); // Should never happen if ft_isoperator is used correctly
}

/**
 * @brief Gets the length of an operator token.
 * @param c		(char) The operator character.
 * @param next	(char) The next character.
 * @return The length of the operator token (1 or 2).
 */
size_t	ft_operator_len(char c, char next)
{
	if ((c == '<' && next == '<') || (c == '>' && next == '>'))
		return (2);
	return (1);
}
