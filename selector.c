/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:02:13 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 18:32:43 by cfeijoo          ###   ########.fr       */
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
	if ((int)(ft_strlen(text) + COL_SEPARATOR) > get_selector()->col_width)
		get_selector()->col_width = ft_strlen(text) + COL_SEPARATOR;
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

void					load_selector(t_selector *selector, int length,
										char **items)
{
	selector->col_width = 0;
	selector->item_list = load_selector_items(length, items);
	selector->cursor = selector->item_list;
	selector->list_length = length;
	selector->cursor_index = 0;
	selector->x = 0;
	selector->y = 10;
}
