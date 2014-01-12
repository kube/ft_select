/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:53:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/12 22:09:25 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static void				place_cursor(t_selector *selector, int index)
{
	int					x;
	int					y;

	x = (index / selector->height) * selector->col_width;
	y = index % selector->height;
	move_cursor(x, y);
}

void					draw_item(t_selector *selector, t_select_item *item,
									int index)
{
	if (is_too_small(selector))
		return ;
	place_cursor(selector, index);
	if (item == selector->cursor)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	if (item->selected == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	ft_putstr_fd(item->text, get_ttyout());
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

void					draw_list(t_selector *selector)
{
	int					fd;
	t_select_item		*current_item;
	int					current_index;

	fd = get_ttyout();
	current_index = 0;
	current_item = selector->item_list;
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	while (current_index < selector->list_length)
	{
		draw_item(selector, current_item, current_index);
		current_item = current_item->next;
		current_index++;
	}
}
