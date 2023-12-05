/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:46:31 by damachad          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "structs.h"
# include "lexer.h"

// Located in *parser_utils.c*
t_tree_node	*command_node(t_lexer **start, t_lexer *end, t_shell *sh);

// Located in *parser.c*
void		list_to_array(t_lexer *start, t_lexer *end, char ***cmd);
t_tree_node	*build_tree(t_lexer **start, t_shell *sh);

#endif
