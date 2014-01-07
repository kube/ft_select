/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:54:30 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/07 23:33:17 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

struct termios				*get_term()
{
	static struct termios	term;
	return (&term);
}

void						sig_handler(int signo)
{
	if (signo == SIGTERM)
	{
		reset_default_display(get_term());
		exit(1);
	}
}

int 						main(int argc, char **argv)
{
	t_selector				*selector;

	signal(SIGTERM, sig_handler);
	if (argc > 1)
	{
		if (init_display(get_term()))
			return (1);
		selector = load_selector(argc - 1, argv + 1);
		display_list(selector);
		while (check_keyboard(selector) && selector->item_list)
			display_list(selector);
		reset_default_display(get_term());
	}
	return (0);
}
