/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:01:17 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/12 14:58:16 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int			tputs_putchar(int c)
{
	write(get_ttyout(), &c, 1);
	return (1);
}

void		move_cursor(unsigned int x, unsigned int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, tputs_putchar);
}
