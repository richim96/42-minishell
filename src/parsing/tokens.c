/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:08:51 by rmei              #+#    #+#             */
/*   Updated: 2025/06/09 19:51:43 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Creates a new token.
 * @param type	(t_token_type) The type of the token.
 * @param value	(const char *) The string value of the token.
 * @param len	(size_t) The length of the token in the original input string.
 * @return Pointer to the newly created t_token, or NULL on allocation failure.
 */
static t_token	*ft_make_token(t_token_type type, const char *value, size_t len)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->len = len;
	token->value = NULL;
	if (value && len >= 0)
	{
		token->value = ft_substr(value, 0, len);
		if (!token->value)
		{
			free(token);
			return (NULL); 
		}
	}
	return (token);
}

/**
 * @brief Appends a new token to a linked list.
 * @param head	(t_list **) Pointer to the head of the list.
 * @param type	(t_token_type) The type of the token to add.
 * @param value	(const char *) Pointer to the start of the token's value.
 * @param len	(size_t) The length of the token.
 * @return 1 on success, 0 on failure (e.g., memory allocation error).
 */
int	ft_add_token(
	t_list **head, t_token_type type, const char *value, size_t len)
{
	t_token	*new_token;
	t_list	*new_node;

	new_token = ft_make_token(type, value, len);
	if (!new_token)
		return (0);
	new_node = ft_lstnew(new_token);
	if (!new_node)
	{
		free(new_token->value);
		free(new_token);
		return (0);
	}
	ft_lstadd_back(head, new_node);
	return (1);
}

/**
 * @brief Frees the content of a token.
 */
void	ft_free_token(void *token_ptr)
{
	t_token	*token;

	if (!token_ptr)
		return;
	token = (t_token *)token_ptr;
	free(token->value);
	token->value = NULL;
	free(token);
}
