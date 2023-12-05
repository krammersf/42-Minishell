/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:27:26 by damachad          #+#    #+#             */
/*   Updated: 2023/11/23 11:36:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "structs.h"

// Located in *prompt.c*
void	empty_line(t_shell *sh);
void	line_empty_test(t_shell *sh);
char	*get_prompt(t_shell *sh);

#endif
