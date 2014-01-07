/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:54:30 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 19:23:34 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static int				check_keyboard(t_selector *selector)
{
	int					key;

	key = 0;
	read(0, (char*)&key, 4);
	system("clear");
	if (key == 4283163)
	 	selector->cursor = selector->cursor->prev;
	if (key == 4348699)
	 	selector->cursor = selector->cursor->next;
	if (key == 27)
		return (0);
	if (key == 32)
		selector->cursor->selected = 1 - selector->cursor->selected;
	if (key == 2117294875)
		delete_current_item(selector);
	return (1);
}

static int				init_display(struct termios *term)
{
	char				buff[2048];

	if (tgetent(buff, getenv("xterm")) < 1)
		return (1);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tcgetattr(0, term);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	return (0);
}

static void				reset_default_display(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}

int 					main(int argc, char **argv)
{
	struct termios		term;
	t_selector			*selector;

	if (argc > 1)
	{
		if (init_display(&term))
			return (1);
		selector = load_selector(argc - 1, argv + 1);
		display_list(selector);
		while (check_keyboard(selector) && selector->item_list)
			display_list(selector);
		reset_default_display(&term);
	}
	return (0);
}
