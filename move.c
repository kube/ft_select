/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:15:03 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/12 22:21:51 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static t_select_item	*get_next_iter(t_select_item *item, int n)
{
	while (n)
	{
		if (n > 0)
		{
			item = item->next;
			n--;
		}
		else
		{
			item = item->prev;
			n++;
		}
	}
	return (item);
}

void		move_right(t_selector *s)
{
	if ((int)s->cursor_index + (int)s->height < s->list_length)
	{
		s->cursor = get_next_iter(s->cursor, s->height);
		draw_item(s, get_next_iter(s->cursor, -s->height),
				s->cursor_index);
		s->cursor_index += s->height;
	}
	draw_item(s, s->cursor, s->cursor_index);
}

void		move_left(t_selector *s)
{
	if ((int)s->cursor_index - (int)s->height >= 0)
	{
		s->cursor = get_next_iter(s->cursor, -s->height);
		draw_item(s, get_next_iter(s->cursor, s->height),
					s->cursor_index);
		s->cursor_index -= s->height;
	}
	draw_item(s, s->cursor, s->cursor_index);
}

void		move_up(t_selector *selector)
{
 	selector->cursor = selector->cursor->prev;
	draw_item(selector, selector->cursor->next, selector->cursor_index);
	selector->cursor_index += selector->list_length - 1;
	selector->cursor_index %= selector->list_length;
	draw_item(selector, selector->cursor, selector->cursor_index);
}

void		move_down(t_selector *selector)
{
 	selector->cursor = selector->cursor->next;
	draw_item(selector, selector->cursor->prev, selector->cursor_index);
	selector->cursor_index++;
	selector->cursor_index %= selector->list_length;
	draw_item(selector, selector->cursor, selector->cursor_index);
}
