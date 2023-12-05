/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:13 by fde-carv          #+#    #+#             */
/*   Updated: 2023/11/30 17:20:11 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"
# include "structs.h"

// Located in *heredoc_utils.c*
void	heredoc_maker(t_lexer *heredoc_node, t_shell *sh);

// Located in *heredoc.c*
void	remove_quotes_heredoc(char *str);
void	heredoc_check(t_lexer *lexer, t_shell *sh);

// Located in *open_pipe.c*
void	herestr_child(t_shell *sh);
char	*open_pipe(t_shell *sh);

// Located in *open_pipe_2.c*
bool	pipes_together(char *str);
void	open_pipes_child(t_shell *sh);
bool	is_solo_pipe(char *str);
bool	consecutive_pipes(char *str);
char	*ft_strstr(char *haystack, char *needle);

#endif