/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:11:37 by kube              #+#    #+#             */
/*   Updated: 2014/01/07 23:32:54 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int			init_display(struct termios *term)
{
	char	buff[2048];

	if (tgetent(buff, getenv("xterm")) < 1)
		return (1);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tcgetattr(0, term);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	return (0);
}

void		reset_default_display(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}
