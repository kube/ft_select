/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:01:17 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/08 22:04:33 by cfeijoo          ###   ########.fr       */
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
	tputs(tgoto(tgetstr("CM", NULL), x, y), 1, tputs_putchar);
}
