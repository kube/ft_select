/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:11:37 by kube              #+#    #+#             */
/*   Updated: 2014/01/12 21:59:28 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int						init_display(struct termios *term)
{
	char				buff[2048];

	if (tgetent(buff, getenv("TERM")) < 1)
		return (1);
	tcgetattr(0, term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	tcsetattr(0, 0, term);
	return (0);
}

void					reset_default_display(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}

static void				draw_too_small(t_selector *selector)
{
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	move_cursor(selector->width / 2 - 4, selector->height / 2);
	write(selector->ttyout, "Too small", 9);
}

int						is_too_small(t_selector *s)
{
	return (s->list_length / s->height + 1 > s->width / s->col_width);
}

void					update_size(t_selector *s)
{
	struct winsize		w;

	ioctl(s->ttyout, TIOCGWINSZ, &w);
	s->width = w.ws_col;
	s->height = w.ws_row;
	if (is_too_small(s))
		draw_too_small(s);
	else
		draw_list(s);
}
