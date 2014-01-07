/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:53:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 19:27:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

void				draw_item(t_select_item *item, t_select_item *cursor)
{
	if (item == cursor)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	if (item->selected == 1)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	ft_putstr(item->text);
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	ft_putchar('\n');
}

void				display_list(t_selector *selector)
{
	t_select_item	*current;
	t_select_item	*first_list_item;

	if (selector->item_list)
	{
		first_list_item = selector->item_list;
		current = first_list_item;
		draw_item(current, selector->cursor);
		current = current->next;
		while (current != first_list_item)
		{
			draw_item(current, selector->cursor);
			current = current->next;
		}
	}
}
