/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 22:17:15 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 23:04:10 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_get_flag(t_printf *p, const char *format)
{
	if (format[p->index] == '#')
		p->flags->sharp = 1;
	else if (format[p->index] == '0')
		p->flags->zero = 1;
	else if (format[p->index] == '-')
		p->flags->less = 1;
	else if (format[p->index] == ' ')
		p->flags->space = 1;
	else if (format[p->index] == '+')
		p->flags->plus = 1;
	++p->index;
}
