/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:53:37 by fde-carv          #+#    #+#             */
/*   Updated: 2023/11/28 17:41:12 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include "structs.h"

// Located at *command_handling.c*
char	*ft_strtok(char *str, char *delimiter);
bool	check_comm(t_shell *sh, char **cmds);
void	execute_comm(t_shell *sh, char **cmds);
void	handle_output_redir(t_shell *sh, t_tree_node *node);
void	handle_input_redir(t_shell *sh, t_tree_node *node);

// Located at *executor_utils.c*
void	handle_command_not_found(t_shell *sh, const char *command);
void	handle_file_not_found(t_shell *sh, const char *file);
void	h_cmd_not_exist(t_shell *sh, const char *cmd, int err_no, char *path);
void	create_pipes(t_shell *sh);
void	close_pipes(t_shell *sh);

// Located at *path.c*
int		is_absolute_path(char *cmd);
char	*search_executable(char *cmd, char *path_env);
char	*find_path(char *cmd, t_shell *sh);
void	null_path(t_shell *sh, char **cmds);

// Located at *executor.c*
void	executor(t_shell *sh, t_tree_node *parser, int i);

#endif
