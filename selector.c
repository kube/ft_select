/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:02:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 19:23:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static t_select_item	*create_list_item(char *text)
{
	t_select_item		*item;

	item = (t_select_item*)malloc(sizeof(t_select_item));
	item->text = text;
	item->selected = 0;
	return (item);
}

static void				add_item_to_list(t_select_item **item_list, char *text)
{
	t_select_item		*item;

	item = create_list_item(text);
	if (*item_list == NULL)
	{
		*item_list = item;
		item->next = item;
		item->prev = item;
	}
	else
	{
		item->prev = (*item_list)->prev;
		item->next = (*item_list);
		(*item_list)->prev->next = item;
		(*item_list)->prev = item;
	}
}

static t_select_item	*load_selector_items(int length, char **items)
{
	int					i;
	t_select_item		*selector_item_list;

	i = 0;
	selector_item_list = NULL;
	while (i < length)
	{
		add_item_to_list(&selector_item_list, items[i]);
		i++;
	}
	return (selector_item_list);
}

void					delete_current_item(t_selector *selector)
{
	t_select_item		*toremove;

	toremove = selector->cursor;
	if (selector->cursor != selector->cursor->next)
	{
		selector->cursor = selector->cursor->next;
		selector->cursor->prev = toremove->prev;
		toremove->prev->next = selector->cursor;
		if (toremove == selector->item_list)
			selector->item_list = toremove->next;
	}
	else
		selector->item_list = NULL;
	free(toremove);
}

t_selector				*load_selector(int length, char **items)
{
	t_selector		*selector;

	selector = (t_selector*)malloc(sizeof(t_selector));
	selector->item_list = load_selector_items(length, items);
	selector->cursor = selector->item_list;
	return (selector);
}
