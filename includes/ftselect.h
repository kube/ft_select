/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftselect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:57:15 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 23:32:56 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSELECT_H
# define FTSELECT_H
# include <unistd.h>
# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <libft.h>

typedef struct				s_select_item
{
	char					*text;
	int						selected;
	struct s_select_item	*prev;
	struct s_select_item	*next;
}							t_select_item;

typedef	struct				s_selector
{
	t_select_item			*item_list;
	t_select_item			*cursor;
}							t_selector;

t_selector		*load_selector(int length, char **items);
int				tputs_putchar(int c);
void			move_cursor_abs(unsigned int x, unsigned int y);
void			move_cursor_rel(int x, int y);
void			move_cursor_rel(int x, int y);
void			delete_current_item(t_selector *selector);
void			draw_item(t_select_item *item, t_select_item *cursor);
void			display_list(t_selector *selector);
int				init_display(struct termios *term);
void			reset_default_display(struct termios *term);
struct termios	*get_term();
void			sig_handler(int signo);
int				check_keyboard(t_selector *selector);

#endif
