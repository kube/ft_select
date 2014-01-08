/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:14:50 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/08 22:06:09 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static void			check_selected(t_select_item *item)
{
	if (item->selected)
	{
		write(1, item->text, ft_strlen(item->text));
		write(1, " ", 1);
	}
}

void				return_selected(t_selector *selector)
{
	t_select_item	*current;

	reset_default_display(get_term());
	current = selector->item_list;
	check_selected(current);
	current = current->next;
	while (current != selector->item_list)
	{
		check_selected(current);
		current = current->next;
	}
	exit (0);
}
