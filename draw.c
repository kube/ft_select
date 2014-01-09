/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:53:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 19:41:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static t_select_item	*goto_item(t_select_item *list, int index)
{
	while (index)
	{
		list = list->next;
		index--;
	}
	return (list);
}

void					draw_item(t_selector *selector, t_select_item *item)
{
	if (item == selector->cursor)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	if (item->selected == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	ft_putstr_fd(item->text, get_ttyout());
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void				draw_column(t_selector *selector, int current_index)
{
	t_select_item		*current_item;

	current_item = goto_item(selector->item_list, current_index);
	draw_item(selector, current_item);
	current_item = current_item->next;
	current_index = (current_index + 1) % selector->list_length;
	write(1, "\n", 1);
	while (current_item != selector->item_list && current_index)
	{
		draw_item(selector, current_item);
		current_item = current_item->next;
		current_index = (current_index + 1) % selector->list_length;
		write(1, "\n", 1);
	}
}

void					draw_list(t_selector *selector)
{
	int					fd;
	int					current_index;

	fd = get_ttyout();
	current_index = 0;
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	move_cursor_abs(selector->x, selector->y);
	while (current_index < selector->list_length)
	{
		draw_column(selector, current_index);
		current_index = current_index + selector->height;
		move_cursor_rel(selector->col_width, -(selector->height - selector->y));
	}
}
