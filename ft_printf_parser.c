/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:58:41 by mapandel          #+#    #+#             */
/*   Updated: 2017/01/24 21:59:01 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_printf_parser_index_n_width(t_printf *print,
	const char *format)
{
	if (format[print->i] != '0'
		&& (print->parser->tmp = ft_atoi(&format[print->i])))
	{
		if (print->parser->tmp < 1)
			exit (-1);
		while (ft_isdigit(format[print->i]))
		++print->i;
		if (format[print->i] == '$' && print->parser->index == -1)
		{
			++print->i;
			print->parser->index = print->parser->tmp;
		}
		else
			print->parser->width = print->parser->tmp;
		return (1);
	}
	return (0);
}

static int		ft_printf_parser_precision(t_printf *print, const char *format)
{
	if (format[print->i] == '.')
	{
		if ((print->parser->tmp = ft_atoi(&format[++print->i])))
		{
			if (format[print->i] == '-')
				++print->i;
			while (ft_isdigit(format[print->i]))
				++print->i;
			if (print->parser->tmp <= 0)
				print->parser->precision = 0;
			else
				print->parser->precision = print->parser->tmp;
		}
		else
			exit (-1);
		return (1);
	}
	return (0);
}

static int		ft_printf_parser_flags(t_printf *print,
	const char *format)
{
	if (ft_strrchr("hljz", format[print->i]))
	{
		if (print->parser->changelenth[0])
			ft_strclr(print->parser->changelenth);
		print->parser->changelenth = ft_stradd(print->parser->changelenth,
			format[print->i]);
		if ((format[print->i] == 'l' && format[print->i + 1] == 'l')
			|| (format[print->i] == 'h' && format[print->i + 1] == 'h'))
			print->parser->changelenth = ft_stradd(print->parser->changelenth,
				format[print->i++ + 1]);
		++print->i;
		return (1);
	}
	else if (ft_strrchr("#0-+ ", format[print->i]))
	{
		if (!ft_strrchr(print->parser->flag, format[print->i]))
			print->parser->flag = ft_stradd(print->parser->flag,
				format[print->i]);
		++print->i;
		return (1);
	}
	return (0);
}

void	ft_printf_parser(t_printf *print, const char *format)
{
	++print->i;
	while (format[print->i] && !ft_strrchr("sSpdDioOuUxXcCeEfFgGaAn",
		format[print->i]))
	{
		if (ft_printf_parser_index_n_width(print, format)
			|| ft_printf_parser_precision(print, format)
			|| ft_printf_parser_flags(print, format))
			(void)print->i;
		else
			exit (-1);
	}
	if (ft_strrchr("sSpdDioOuUxXcCeEfFgGaAn", format[print->i]))
		print->parser->conv = ft_stradd(print->parser->conv, format[print->i]);
	else
		exit (-1);
	++print->i;
	ft_printf_conv(print);
}
