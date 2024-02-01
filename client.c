/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:47:57 by ashalagi          #+#    #+#             */
/*   Updated: 2023/06/12 08:41:42 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int	g_confirm = 0;

static long	ft_drop(char *p)
{
	long	i;

	i = 0;
	while (p[i] != '\0' && (p[i] == '\t' || p[i] == '\n' || p[i] == '\r'
			|| p[i] == '\v' || p[i] == '\f' || p[i] == ' '))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	char	*p;
	long	i;
	long	num;
	int		minus;

	minus = 0;
	p = (char *)str;
	i = ft_drop(p);
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			minus++;
		i++;
	}
	num = 0;
	while (p[i] && p[i] >= 48 && p[i] <= 57)
	{
		num = num * 10 + (p[i] - '0');
		i++;
	}
	if (minus == 1)
		return (-num);
	return (num);
}

void	ft_client_handler(int signal)
{
	if (signal == SIGUSR1)
		g_confirm = 1;
	if (signal == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(0);
	}
}

void	send_symbol(int pid, char c)
{
	int	n;

	n = 128;
	while (n > 0)
	{
		usleep(20);
		g_confirm = 0;
		if (c & n)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n = n / 2;
		while (1)
		{
			if (g_confirm)
				break ;
			usleep(1);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi((const char *)argv[1]);
		signal (SIGUSR1, ft_client_handler);
		signal (SIGUSR2, ft_client_handler);
		if (pid == 0 || pid < 0)
		{
			ft_printf("Invalid PID!\n");
			return (0);
		}
		while (argv[2][i] != '\0')
		{
			send_symbol (pid, argv [2][i]);
			i++;
		}
		send_symbol(pid, argv[2][i]);
		return (0);
	}
	else
		ft_printf("Invalid parameters! Try: ./client [PID] [STRING_TO_PASS]\n");
	return (0);
}
