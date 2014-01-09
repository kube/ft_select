/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:53:39 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/08 22:05:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

void				draw_item(t_selector *selector, t_select_item *item,
								t_select_item *cursor, int fd)
{
	if (item == cursor)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	if (item->selected == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	ft_putstr_fd(item->text, get_ttyout());
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	write(fd, "\n", 1);
	(void)selector;
}

void				draw_list(t_selector *selector)
{
	int				fd;
	t_select_item	*current;
	t_select_item	*first_list_item;

	fd = get_ttyout();
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	move_cursor_abs(selector->x, selector->y);
	if (selector->item_list)
	{
		first_list_item = selector->item_list;
		current = first_list_item;
		draw_item(selector, current, selector->cursor, fd);
		current = current->next;
		while (current != first_list_item)
		{
			draw_item(selector, current, selector->cursor, fd);
			current = current->next;
		}
	}
	ft_putnbr_fd(selector->width, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(selector->height, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(selector->cursor_index, fd);
}
