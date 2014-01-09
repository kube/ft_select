/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:11:37 by kube              #+#    #+#             */
/*   Updated: 2014/01/08 22:01:09 by cfeijoo          ###   ########.fr       */
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

void					update_size()
{
	struct winsize		w;

	ioctl(get_ttyout(), TIOCGWINSZ, &w);
	get_selector()->width = w.ws_col;
	get_selector()->height = w.ws_row;
	draw_list(get_selector());
}
