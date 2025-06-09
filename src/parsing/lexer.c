/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:13:44 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:54:40 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Skips whitespace characters in the input string.
 * @param input	(const char **) Current position in the input string.
 */
static void	ft_skip_whitespace(const char **input)
{
	while (**input && ft_isspace(**input))
		(*input)++;
}

/**
 * @brief Tokenizes the input_line and returns a list of tokens.
 * @param input_line	(const char *) The raw command line string.
 * @return A t_list of t_token structures, or NULL on failure/empty input.
 */
t_list	*ft_tokenize(const char *input_line)
{
	const char	*c;
	t_list		*tokens;
	size_t		len;

	if (!input_line)
		return (NULL);
	tokens = NULL;
	c = input_line;
	while (*c)
	{
		ft_skip_whitespace(&c);
		if (!*c)
			break;
		if (ft_isquote(*c))
		{
			if (!ft_handle_quotes(&c, &tokens))
			{
				ft_lstclear(&tokens, ft_free_token);
				return (NULL);
			}
		}
		else if (ft_isoperator(*c))
		{
			len = ft_operator_len(*c, *(c + 1));
			if (!ft_add_token(&tokens, ft_operator_type(*c, *(c + 1)), c, len))
			{
				ft_lstclear(&tokens, ft_free_token);
				return (NULL);
			}
			c += len;
		}
		else
		{
			len = 0;
			while (c[len] && !ft_isspace(c[len]) && !ft_isoperator(c[len]) && !ft_isquote(c[len]))
				len++;
			if (len > 0)
			{
				if (!ft_add_token(&tokens, WORD, c, len))
				{
					ft_lstclear(&tokens, ft_free_token);
					return (NULL);
				}
				c += len;
			}
		}
	}
	if (!ft_add_token(&tokens, END_OF_FILE, NULL, 0))
	{
		ft_lstclear(&tokens, ft_free_token);
		return (NULL);
	}
	return (tokens);
} 
