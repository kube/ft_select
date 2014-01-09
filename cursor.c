/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:01:17 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 18:28:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int			tputs_putchar(int c)
{
	write(get_ttyout(), &c, 1);
	return (1);
}

void		move_cursor_abs(unsigned int x, unsigned int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, tputs_putchar);
}

void		move_cursor_rel(int x, int y)
{
	if (x > 0)
	{
		while (x > 0)
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			x--;
		}
	}
	else
	{
		while (x < 0)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			x++;
		}
	}
	if (y > 0)
	{
		while (y > 0)
		{
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
			y--;
		}
	}
	else
	{
		while (y < 0)
		{
			tputs(tgetstr("up", NULL), 1, tputs_putchar);
			y++;
		}
	}
}
