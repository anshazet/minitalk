/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:32:38 by ashalagi          #+#    #+#             */
/*   Updated: 2023/03/08 13:44:17 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(unsigned long a, int cont)
{
	int	len;

	len = 0;
	if (!a)
		return (write(1, "(nil)", 5));
	if (cont == 1)
	{
		len += write(1, "0x", 2);
		cont = 0;
	}
	if (a >= 16)
		len += ft_type_p(a / 16, cont);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (len + 1);
}
