/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:25:52 by damachad          #+#    #+#             */
/*   Updated: 2023/11/23 17:25:56 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Reset the index structure
void	reset_index(t_index *index)
{
	index->i = 0;
	index->j = 0;
	index->k = 0;
	index->squote = 0;
	index->dquote = 0;
}

// Free the allocated memory for a lexer list
void	free_lexer_list(t_lexer *head)
{
	t_lexer	*current;
	t_lexer	*next;

	current = head;
	next = NULL;
	if (!head)
		return ;
	while (current)
	{
		next = current->next;
		if (current->str)
		{
			free(current->str);
			current->str = NULL;
		}
		free(current);
		current = next;
	}
}

// Free the allocated memory for a 2d array
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

// Free the allocated memory for a not-NULL-terminated 2d array
void	free_int_matrix(t_shell *sh)
{
	int	i;

	i = -1;
	if (sh == NULL || sh->pipes == NULL)
		return ;
	while (++i < sh->nbr_commands)
		free(sh->pipes[i]);
	free(sh->pipes);
}
