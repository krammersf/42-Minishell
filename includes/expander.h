/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:09:14 by fde-carv          #+#    #+#             */
/*   Updated: 2023/11/24 18:12:10 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
# include "structs.h"
# include "executor.h"

// Located in *expander_utils.c*
int		remove_nulls(char **cmds, int nbr_cmds);
int		expand_cmds(char *key, int i, int j, char **line);
void	handle_invalid_env(int point, int len, char **line);
void	expand_valid_env(int point, t_shell *sh, char *env_value, char **line);
int		expand_free(char *key, int i, int j, char **line);

// Located in *expand_arg.c*
int		find_dollar(t_shell *sh, int point, char *tmp, char **line);
int		check_quotes_str(const char *str, t_shell *sh);
void	env_expand_dollar(t_shell *sh, char *tmp, char **line);
void	update_cmds(t_shell *sh, char *value, char **line);

// Located in *expander.c*
void	space_pipes(t_shell *sh, char *tmp);
void	expander(char ***cmds, t_shell *sh);
char	*trim_spaces(t_shell *sh, char *str);

#endif