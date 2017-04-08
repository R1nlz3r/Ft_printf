/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 01:57:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/08 01:57:37 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_get_precision(t_printf *p, const char *format)
{
	int		tmp;
	int		i;

	i = 0;
	++p->index;
	while (format[p->index] == '0')
		++p->index;
	if ((tmp = ft_atoi(&format[p->index]) < 0)
		|| !ft_isdigit(format[p->index]))
	{
		ft_putnbr(tmp);
		p->precision = 0;
		return ;
	}
	ft_putnbr(tmp);
	p->precision = tmp;
	while (ft_isdigit(format[p->index]))
		++p->index;
}
