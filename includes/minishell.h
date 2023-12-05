/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:26 by damachad          #+#    #+#             */
/*   Updated: 2023/11/29 13:33:24 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/ioctl.h>

# include "../libft/libft.h"
# include "lexer.h"
# include "parser.h"
# include "clean.h"
# include "environment.h"
# include "builtins.h"
# include "structs.h"
# include "prompt.h"
# include "executor.h"
# include "signals.h"
# include "heredoc.h"
# include "expander.h"
# include "print_stuff.h"

// Macros

# define CMD 2
# define SPACES "\t\n\v\f\r "
# define NOT_EXPRESSION "|><&();/ \t\n\v\f\r"
# define OPERATORS "<>|"
# define MINISHELL "[MINISHELL]:"
# define HERE "warning: here-document delimited by end-of-file (wanted"
# define UNEXPECTED_TOK "minishell: syntax error near unexpected token\n"
# define UNEXPECTED_EOF "minishell: syntax error: unexpected end of file"
# define INVALID_ID "': not a valid identifier"

//global variable exit code
extern int	g_signo;

// Located at *main.c*
void		reset_loop(t_shell *sh);
void		ft_loop(t_shell *sh);

#endif
