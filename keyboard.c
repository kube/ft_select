/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 23:13:36 by kube              #+#    #+#             */
/*   Updated: 2014/01/08 02:16:46 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

int			check_keyboard(t_selector *selector)
{
	int		key;

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
		selector->cursor_index ++;
		selector->cursor_index %= selector->list_length;
	}
	if (key == 27)
		return (0);
	if (key == 32)
		selector->cursor->selected = 1 - selector->cursor->selected;
	if (key == 2117294875 || key == 127)
		delete_current_item(selector);
	return (1);
}
