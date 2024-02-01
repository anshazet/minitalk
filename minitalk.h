/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:12:27 by ashalagi          #+#    #+#             */
/*   Updated: 2023/06/12 09:44:52 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include <signal.h>

extern char	g_phrase[10000000];

int		ft_strlen(char *str);
void	init_phrase(void);

#endif
