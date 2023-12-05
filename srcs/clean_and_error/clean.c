/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:56:40 by damachad          #+#    #+#             */
/*   Updated: 2023/11/24 14:53:59 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//	Free the allocated memory
void	free_shell_fields(t_shell *sh)
{
	if (sh->ui)
		free(sh->ui);
	if (sh->lexer)
		free_lexer_list(sh->lexer);
	if (sh->parser)
		free_parser_tree(sh->parser);
	if (sh->env_lst)
		free_env_lst(sh->env_lst);
	if (sh->mini_env)
		free_matrix(sh->mini_env);
	if (sh->index)
		free(sh->index);
	if (sh->home)
		free(sh->home);
	if (sh->prompt)
		free(sh->prompt);
	if (sh->pipes)
		free_int_matrix(sh);
	if (sh->files)
		free(sh->files);
}

// Clear the shell structure
void	clear_shell(t_shell *sh)
{
	free_shell_fields(sh);
	sh->ui = NULL;
	sh->lexer = NULL;
	sh->parser = NULL;
	sh->env_lst = NULL;
	sh->mini_env = NULL;
	sh->index = NULL;
	sh->home = NULL;
	sh->prompt = NULL;
	sh->pipes = NULL;
	sh->files = NULL;
	sh->cmds = NULL;
	close(2);
}

//	Auxiliary function for lexer_deltwo
void	delete_two_nodes(t_lexer **lexer, t_lexer *curr, t_lexer *prev)
{
	t_lexer	*tmp;

	if (prev)
		prev->next = curr->next->next;
	else
	{
		if (!curr->prev)
		{
			*lexer = curr->next->next;
			if (*lexer)
				(*lexer)->prev = NULL;
		}
		else
		{
			prev = curr->prev;
			prev->next = curr->next->next;
			*lexer = curr->next->next;
		}
	}
	tmp = curr->next;
	lexer_free_node(curr);
	lexer_free_node(tmp);
}

//	Free the allocated memory for two consecutive nodes 
//  from the lexer linked list
void	lexer_deltwo(t_lexer **lexer, int key)
{
	t_lexer	*curr;
	t_lexer	*prev;

	curr = *lexer;
	prev = NULL;
	if (!(*lexer))
		return ;
	while (curr && curr->next)
	{
		if (curr->i == key)
		{
			delete_two_nodes(lexer, curr, prev);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

//	Free the allocated memory for a node from the lexer linked list
void	lexer_free_node(t_lexer *node)
{
	if (node)
	{
		if (node->str)
			free(node->str);
		node->prev = NULL;
		free(node);
	}
}
