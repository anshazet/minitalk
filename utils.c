/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:57:29 by ashalagi          #+#    #+#             */
/*   Updated: 2023/06/12 09:44:02 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
#include <stdio.h>

extern char	g_phrase[10000000];

void	init_phrase(void)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		g_phrase[i] = '\0';
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
