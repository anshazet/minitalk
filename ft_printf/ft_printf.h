/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:11:19 by ashalagi          #+#    #+#             */
/*   Updated: 2023/03/13 08:33:02 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_work_types(va_list *args, char c);
int		ft_putchar_printf(char a);
int		ft_string(char *str);
int		ft_type_di(int a);
int		ft_type_p(unsigned long a, int cont);
int		ft_type_u(unsigned int a);
int		ft_type_x(unsigned int a, char c);

#endif
