/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:48:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/08 18:29:43 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_get_star_width(t_printf *p)
{
	int		star;

	++p->index;
	star = va_arg(p->ap, int);
	if (star < 0)
	{
		if (star == -2147483648)
			return ;
		p->flags->less = 1;
		p->width = star * -1;
	}
	else
		p->width = star;
}

void			ft_printf_get_width(t_printf *p, const char *format)
{
	int		tmp;
	char	tmp_intmax_buffer;
	int		i;

	i = 0;
	if (format[p->index] == '*')
	{
		ft_printf_get_star_width(p);
		return ;
	}
	tmp = ft_atoi(&format[p->index]);
	tmp_intmax_buffer = format[p->index];
	while (ft_isdigit(format[p->index + i]) && i < 11)
		++i;
	while (ft_isdigit(format[p->index]))
		++p->index;
	if (tmp < 0 || i >= 11 || (i == 10 && tmp_intmax_buffer > '2'))
		return ;
	p->width = tmp;
}
