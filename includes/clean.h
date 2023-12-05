/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:58:17 by damachad          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:58 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "minishell.h"
# include "structs.h"

// Located in *clean.c*
void	clear_shell(t_shell *sh);
void	lexer_deltwo(t_lexer **lexer, int key);
void	lexer_free_node(t_lexer *node);

// Located in *clean2.c*
void	reset_index(t_index *index);
void	free_lexer_list(t_lexer *head);
void	free_matrix(char **matrix);
void	free_int_matrix(t_shell *sh);

// Located in *clean3.c*
void	delete_heredoc_list(t_shell *sh);
void	free_parser_tree(t_tree_node *root);
void	free_lexer_list_rev(t_lexer **tail);
void	mini_clean(t_shell *sh, int i);
void	handle_empty_line_herestr(t_shell *sh, int fd);

// Located in *error.c*
bool	double_operator(t_lexer *lexer);
int		is_syntax_correct(t_lexer *lexer);
int		error_3s(t_shell *sh, char *str1, char *str2, char *str3);
void	error_4s(char *str1, char *str2, char *str3, char *str4);
bool	empty_redir(t_lexer *lexer);

#endif
