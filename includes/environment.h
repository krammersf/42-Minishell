/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:06:03 by damachad          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"
# include "structs.h"

// Located in *env.c*
t_envlst	*ft_lstnew_env(char *key, char *value, int visible);
char		*get_key(char *mini_env);
char		*get_value(char *mini_env);
void		create_env_list(t_shell *sh);

// Located in *env_utils.c*
void		free_env_lst(t_envlst *env_lst);
void		free_node_env(t_envlst *node);
void		free_nodes_env(t_envlst **list);
char		**copy_envp(char **envp);
void		ft_lstadd_back_env(t_envlst **head, t_envlst *new_node);

// Located in *envlst_use.c*
int			ft_list_size_env(t_envlst *list);
void		join_mini_env(t_envlst *env_lst, char **mini_env, int i);
void		update_mini_env(t_shell *sh);
char		*get_env_value(t_shell *sh, char *key);
int			change_env_value(t_shell *sh, char *key, char *new_value);

// Located in *builtin_env.c*
void		print_env_list(t_shell *sh);

#endif
