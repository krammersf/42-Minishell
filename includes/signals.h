/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:40:09 by damachad          #+#    #+#             */
/*   Updated: 2023/11/29 13:21:20 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"
# include "structs.h"

// Located in signals.c
void	sigint_handler(int signo);
void	sighandler_child(int signo);
void	reset_signals(void);

// Located in signals2.c
void	set_exit_status(t_shell *sh, int status);
void	heredoc_handler(int signo);

#endif
