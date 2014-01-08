/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:54:30 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/08 02:42:26 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

struct termios				*get_term()
{
	static struct termios	term;
	return (&term);
}

t_selector					*get_selector()
{
	static t_selector		selector;
	return (&selector);
}

void						update_size()
{
	struct winsize			w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    get_selector()->width = w.ws_col;
    get_selector()->height = w.ws_row;
	draw_list(get_selector());
}

void						sig_handler(int signo)
{
	int						cp;
	
	if (signo == SIGCONT)
	{
		signal(SIGTSTP, sig_handler);
		init_display(get_term());
		update_size();
	}
	else if (signo == SIGWINCH)
		update_size();
	else
	{
		reset_default_display(get_term());
		if (signo == SIGTSTP)
		{
			signal(SIGTSTP, SIG_DFL);
			cp = get_term()->c_cc[VSUSP];
		    ioctl(0, TIOCSTI, (char*)&cp); 
		}
		else
			exit(1);
	}
}

int 						main(int argc, char **argv)
{
	t_selector				*selector;

	signal(SIGCONT, sig_handler);
	signal(SIGWINCH, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGHUP, sig_handler);
	if (argc > 1)
	{
		if (init_display(get_term()))
			return (1);
		selector = get_selector();
		load_selector(selector, argc - 1, argv + 1);
		update_size();
		while (check_keyboard(selector) && selector->item_list)
			draw_list(selector);
		reset_default_display(get_term());
	}
	return (0);
}
