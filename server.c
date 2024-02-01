/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:27:16 by ashalagi          #+#    #+#             */
/*   Updated: 2023/06/12 09:44:30 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
#include <stdio.h>

char	g_phrase[10000000];

static void	write_nbr(int n)
{
	char	*p;

	p = "0123456789";
	if (n / 10)
		write_nbr (n / 10);
	write (1, &p[n % 10], 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n *= (-1);
	}
	write_nbr(n);
}

void	ft_put_symbol(unsigned char c, int pid)
{
	if (c == 0)
	{
		write(1, g_phrase, ft_strlen(g_phrase));
		write(1, "\n", 1);
		kill(pid, SIGUSR2);
		init_phrase();
	}
	else
	{
		g_phrase[ft_strlen(g_phrase)] = c;
		kill(pid, SIGUSR1);
	}
}

void	ft_take_signal(int signal, siginfo_t *sig, void *context)
{
	static unsigned char	c = 0;
	static int				n = 128;

	if (n > 0)
	{
		if (signal == SIGUSR1)
			c += n;
		n = n / 2;
	}
	if (n == 0)
	{
		ft_put_symbol(c, sig->si_pid);
		c = 0;
		n = 128;
	}
	else
		kill(sig->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	int					pid;
	struct sigaction	mt;

	init_phrase();
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	mt.sa_flags = SA_SIGINFO;
	mt.sa_sigaction = ft_take_signal;
	sigaction(SIGUSR1, &mt, NULL);
	sigaction(SIGUSR2, &mt, NULL);
	while (1)
		usleep(1);
	return (0);
}
