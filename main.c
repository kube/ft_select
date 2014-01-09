/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:54:30 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 14:12:29 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

t_selector					*get_selector()
{
	static t_selector		selector;
	return (&selector);
}

struct termios				*get_term()
{
	return (&get_selector()->term);
}

int							get_ttyout()
{
	return (get_selector()->ttyout);
}

void						define_ttyout(t_selector *selector)
{
	if (isatty(1))
		selector->ttyout = 1;
	else
		selector->ttyout = open("/dev/tty", O_RDWR);
}

int 						main(int argc, char **argv)
{
	struct termios			*term;
	t_selector				*selector;

	if (argc > 1)
	{
		init_signals();
		term = get_term();
		if (init_display(term))
			return (1);
		selector = get_selector();
		define_ttyout(selector);
		load_selector(selector, argc - 1, argv + 1);
		update_size(selector);
		while (check_keyboard(selector) && selector->item_list)
		{
			draw_list(selector);
		}
		reset_default_display(term);
		ft_putnbr(get_ttyout());
	}
	return (0);
}
