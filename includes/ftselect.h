/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftselect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:57:15 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 18:33:52 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSELECT_H
# define FTSELECT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <libft.h>
# include <sys/ioctl.h>

# define COL_SEPARATOR 2

typedef struct				s_select_item
{
	char					*text;
	int						selected;
	struct s_select_item	*prev;
	struct s_select_item	*next;
}							t_select_item;

typedef	struct				s_selector
{
	struct termios			term;
	int						ttyout;
	unsigned int			width;
	unsigned int			height;
	unsigned int			x;
	unsigned int			y;
	t_select_item			*item_list;
	t_select_item			*cursor;
	int						list_length;
	int						col_width;
	int						cursor_index;
}							t_selector;

struct termios	*get_term();
t_selector		*get_selector();
int				get_ttyout();
void			load_selector(t_selector *selector, int length, char **items);
int				tputs_putchar(int c);
void			move_cursor_abs(unsigned int x, unsigned int y);
void			move_cursor_rel(int x, int y);
void			move_cursor_rel(int x, int y);
void			delete_current_item(t_selector *selector);
void			draw_item(t_selector *selector, t_select_item *item);
void			draw_list(t_selector *selector);
int				init_display(struct termios *term);
void			reset_default_display(struct termios *term);
void			sig_handler(int signo);
int				check_keyboard(t_selector *selector);
void			init_signals();
void			update_size();
void			return_selected(t_selector *selector);

#endif
