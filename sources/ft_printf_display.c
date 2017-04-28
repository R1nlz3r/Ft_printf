/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:57:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/27 06:52:55 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_display(t_printf *p, const char *format)
{
	size_t		buf;

	while (format[p->index])
	{
		buf = ft_strclen(&format[p->index], '%');
		write(1, &format[p->index], buf);
		p->ret += buf;
		p->index += buf;
		if (format[p->index] == '%')
		{
			if (!format[++p->index])
				break ;
			p = ft_printf_parsing(p, format);
			if (p->error)
				break ;
			p = ft_printf_conv(p);
			if (p->error)
				break ;
			reset_t_printf(p);
		}
	}
}
