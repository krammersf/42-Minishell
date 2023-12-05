/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:11:56 by fde-carv          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STUFF_H
# define PRINT_STUFF_H

# include "structs.h"
# include "minishell.h"

void	print_env_value(t_shell *sh, char *key);
void	print_mini_envp(char **mini_envp);
void	print_tree(t_tree_node *root, int depth);
void	print_lexer(t_lexer *lexer);

#endif