/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:11:37 by kube              #+#    #+#             */
/*   Updated: 2014/01/09 18:38:50 by cfeijoo          ###   ########.fr       */
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

void					update_size(t_selector *selector)
{
	struct winsize		w;

	ioctl(selector->ttyout, TIOCGWINSZ, &w);
	selector->width = w.ws_col;
	selector->height = w.ws_row;
	selector->x = 0;
	selector->y = (selector->height - selector->list_length) / 2;
	draw_list(selector);
}
