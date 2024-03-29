/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 16:47:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/09 17:44:55 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftselect.h>

static void		sig_winch()
{
	update_size(get_selector());
}

static void		sig_tstp()
{
	if (isatty(1))
	{
		reset_default_display(get_term());
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, &get_term()->c_cc[VSUSP]);
	}
}

static void		sig_cont()
{
	signal(SIGTSTP, sig_tstp);
	init_display(get_term());
	update_size(get_selector());
}

static void		sig_term()
{
	reset_default_display(get_term());
	exit(0);
}

void			init_signals()
{
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGWINCH, sig_winch);
	signal(SIGTERM, sig_term);
	signal(SIGINT, sig_term);
	signal(SIGHUP, sig_term);
}
