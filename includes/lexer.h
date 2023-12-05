/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:21:02 by damachad          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include "structs.h"

// Located in *lexer.c*
t_lexer	*last_node(t_lexer *start);
t_lexer	*lexer_new(char *word, int i, t_shell *sh);
void	lexer_add_back(t_lexer **lexer, t_lexer *new);
t_lexer	*ft_lexer(char *ui, t_shell *sh);

// Located in *lexer_utils.c*
bool	is_present(const char *str, char c);
int		is_operator(char *word, t_shell *sh);
void	advance_quote(char *str, int *j, char next_char);
void	advance_word(char *str, int *j);
void	word_end_pos(char *ui, t_shell *sh);

#endif
