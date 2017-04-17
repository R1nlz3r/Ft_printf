/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 01:57:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/17 06:22:32 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_get_star_precision(t_printf *p)
{
	int		star;

	++p->index;
	star = va_arg(p->ap, int);
	p->precision = star;
	if (star < 0)
		p->precision = -1;
}

void			ft_printf_get_precision(t_printf *p, const char *format)
{
	int		tmp;
	char	tmp_intmax_buffer;
	int		i;

	i = 0;
	++p->index;
	if (format[p->index] == '*')
	{
		ft_printf_get_star_precision(p);
		return ;
	}
	tmp = ft_atoi(&format[p->index]);
	while (format[p->index] == '0')
		++p->index;
	tmp_intmax_buffer = format[p->index];
	while (ft_isdigit(format[p->index + i]) && i < 11)
		++i;
	if (!ft_isdigit(format[p->index]) && !(p->precision = 0))
		return ;
	while (ft_isdigit(format[p->index]))
		++p->index;
	if (tmp < 0 || i > 11 || (i == 10 && tmp_intmax_buffer > '2'))
		return ;
	p->precision = tmp;
}
