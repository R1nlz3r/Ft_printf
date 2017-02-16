/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:57:46 by mapandel          #+#    #+#             */
/*   Updated: 2017/01/29 19:23:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_sS(t_printf *print)
{
	if ((ft_strrchr(print->parser->conv, 's')
		&& print->parser->changelenth[0] == 'l'
		&& !print->parser->changelenth[1])
		|| (ft_strrchr(print->parser->conv, 'S')))
	{
		//print->result = va_arg(print->args, wchar_t*);
		//print->len += ft_strlen((wchar_t*)print->result);
		//ft_putstr((wchar_t*)print->result);
	}
	else if ((ft_strrchr(print->parser->conv, 's')))
	{
		print->result = va_arg(print->args, char*);
		print->len += ft_strlen(print->result);
		ft_putstr(print->result);
	}
}

void	ft_printf_c(t_printf *print)
{
	if (ft_strrchr(print->parser->conv, 'c'))
	{
		print->result[0] = va_arg(print->args, int);
		++print->len;
		ft_putchar(print->result[0]);
	}
}

void	ft_printf_di(t_printf *print)
{
	if (ft_strrchr(print->parser->conv, 'i')
		|| ft_strrchr(print->parser->conv, 'd'))
	{
		print->result = ft_itoabase_signed(va_arg(print->args, int), 10);
		print->len += ft_strlen(print->result);
		ft_putstr(print->result);
	}
}

void	ft_printf_conv(t_printf *print)
{
	int i;

	i = 0;
	while (i < 3)
		(*print->tabptr[i++])(print);
}
