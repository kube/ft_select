/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:13:36 by kube              #+#    #+#             */
/*   Updated: 2014/01/12 22:22:08 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

void					select_current_item(t_selector *selector)
{
	selector->cursor->selected = 1 - selector->cursor->selected;
	draw_item(selector, selector->cursor, selector->cursor_index);
	if (selector->cursor->next != selector->item_list)
	{
		selector->cursor = selector->cursor->next;
		draw_item(selector, selector->cursor->prev, selector->cursor_index);
		selector->cursor_index++;
		draw_item(selector, selector->cursor, selector->cursor_index);
	}
}

int						check_keyboard(t_selector *selector)
{
	int					key;

	key = 0;
	read(0, (char*)&key, 4);
	if (key == 4283163)
		move_up(selector);
	if (key == 4348699)
		move_down(selector);
	if (key == 4414235)
		move_right(selector);
	if (key == 4479771)
		move_left(selector);
	if (key == 10)
		return_selected(selector);
	if (key == 32)
		select_current_item(selector);
	if (key == 2117294875 || key == 127)
		delete_current_item(selector);
	if (key == 27)
		return (0);
	return (1);
}
