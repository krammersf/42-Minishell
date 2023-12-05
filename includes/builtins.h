/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:05:18 by damachad          #+#    #+#             */
/*   Updated: 2023/11/27 17:18:19 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "structs.h"

// Located in *builtin_cd.c*
bool	is_home(t_shell *sh, char **cmds);
int		builtin_cd(t_shell *sh, char **cmds);

// Located in *builtin_echo.c*
int		builtin_echo(char **cmds);

// Located in *builtin_env.c*
int		builtin_env(t_shell *sh, char **cmds);

// Located in *builtin_exit.c*
void	builtin_exit(t_shell *sh, char **cmds);

// Located in *builtin_export.c*
int		builtin_export(t_shell *sh, char **cmds);
// Located in *builtin_export_print.c*
void	print_export(t_shell *sh);

// Located in *builtin_pwd.c*
int		builtin_pwd(t_shell *sh);

// Located in *builtin_unset.c*
int		builtin_unset(t_shell *sh, char **cmds);

// Located in *builtin_main.c*
bool	strn_strl_cmp(char *s1, char *s2);
bool	is_builtin_parent(char **cmd);
bool	is_builtin_child(char **cmd);
int		builtin_router(t_shell *sh, char **cmds);

#endif