/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:57:46 by mapandel          #+#    #+#             */
/*   Updated: 2017/01/24 22:18:23 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*ft_init_tabptr(t_printf *print)
{
	print->tabptr[0] = &ft_printf_di;
	print->tabptr[1] = &ft_printf_c;
	print->tabptr[2] = &ft_printf_sS;
	return (print);
}

static t_printf_parser		*ft_init_printf_parser(t_printf *print)
{
	print->parser->index = -1;
	print->parser->width = -1;
	print->parser->precision = 6;
	print->parser->tmp = 0;
	if (!(print->parser->flag = ft_strnew(0))
		|| !(print->parser->conv = ft_strnew(0))
		|| !(print->parser->changelenth = ft_strnew(0)))
		exit(-1);
	return (print->parser);
}

static t_printf		*ft_init_printf(t_printf *print)
{
	if (!(print = ft_memalloc(sizeof(t_printf)))
		|| !(print->parser = ft_memalloc(sizeof(t_printf_parser))))
		exit (-1);
	print->len = 0;
	print->i = 0;
	print->result = NULL;
	return(print);
}

int   ft_printf(const char *format, ...)
{
	t_printf    *print;
	int         result;

	if (!(print = ft_init_printf((print = NULL))))
		exit (-1);
	print = ft_init_tabptr(print);
	va_start(print->args, format);
	while (format && format[print->i])
	{
		if (format[print->i] == '%' && (print->parser =
			ft_init_printf_parser(print)))
			ft_printf_parser(print, format);
		else if (format[print->i] == '{')
			ft_printf_color(print, &format[++print->i]);
		else
		{
			ft_putchar(format[print->i++]);
			++print->len;
		}
	}
	result = print->len;
	va_end(print->args);
	free(print);
	return (result);
}
