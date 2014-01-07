/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:01:17 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 19:29:41 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int			tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void		move_cursor_abs(unsigned int x, unsigned int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, tputs_putchar);
}

void		move_cursor_rel(int x, int y)
{
	if (x > 0)
		tputs(tgoto(tgetstr("RI", NULL), x, 0), 1, tputs_putchar);
	else
		tputs(tgoto(tgetstr("LE", NULL), -x, 0), 1, tputs_putchar);
	if (y > 0)
		tputs(tgoto(tgetstr("DO", NULL), 0, y), 1, tputs_putchar);
	else
		tputs(tgoto(tgetstr("UP", NULL), 0, -y), 1, tputs_putchar);
}
