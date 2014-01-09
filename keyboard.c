/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:13:36 by kube              #+#    #+#             */
/*   Updated: 2014/01/09 13:48:31 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

void					delete_current_item(t_selector *selector)
{
	t_select_item		*toremove;

	toremove = selector->cursor;
	if (selector->cursor != selector->cursor->next)
	{
		selector->cursor = selector->cursor->next;
		selector->cursor->prev = toremove->prev;
		toremove->prev->next = selector->cursor;
		if (toremove->next == selector->item_list)
		{
			selector->cursor = toremove->prev;
			selector->cursor_index -= 1;
		}
		if (toremove == selector->item_list)
			selector->item_list = toremove->next;
		selector->list_length -= 1;
	}
	else
		selector->item_list = NULL;
	free(toremove);
	update_size(selector);
}

void					select_current_item(t_selector *selector)
{
	selector->cursor->selected = 1 - selector->cursor->selected;
	if (selector->cursor->next != selector->item_list)
	{
		selector->cursor = selector->cursor->next;
		selector->cursor_index++;
	}
}

int						check_keyboard(t_selector *selector)
{
	int					key;

	key = 0;
	read(0, (char*)&key, 4);
	if (key == 4283163)
	{
	 	selector->cursor = selector->cursor->prev;
		selector->cursor_index += selector->list_length - 1;
		selector->cursor_index %= selector->list_length;
	}
	if (key == 4348699)
	{
	 	selector->cursor = selector->cursor->next;
		selector->cursor_index++;
		selector->cursor_index %= selector->list_length;
	}
	if (key == 10)
		return_selected(selector);
	if (key == 27)
		return (0);
	if (key == 32)
		select_current_item(selector);
	if (key == 2117294875 || key == 127)
		delete_current_item(selector);
	return (1);
}
