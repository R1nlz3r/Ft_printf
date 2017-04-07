/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:17:27 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 14:57:59 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_pritnf_get_conv2(t_printf *p, const char *format)
{
	if (format[p->index] == 's' || format[p->index] == 'S')
	{
		p->conv = FT_PRINTF_S;
		if (format[p->index] == 'S')
			p->modifier = FT_PRINTF_L;
	}
	else if (format[p->index] == 'u' || format[p->index] == 'U')
	{
		p->conv = FT_PRINTF_U;
		if (format[p->index] == 'U')
			p->modifier = FT_PRINTF_L;
	}
	else if (format[p->index] == 'x')
		p->conv = FT_PRINTF_X;
	else if (format[p->index] == 'X')
		p->conv = FT_PRINTF_XX;
	else if (format[p->index] == '%')
		p->conv = FT_PRINTF_PERCENT;
	else
		p->conv = FT_PRINTF_WAIT_INPUT;
}

void			ft_printf_get_conv(t_printf *p, const char *format)
{
	if (format[p->index] == 'c' || format[p->index] == 'C')
	{
		p->conv = FT_PRINTF_C;
		if (format[p->index] == 'C')
			p->modifier = FT_PRINTF_L;
	}
	else if (format[p->index] == 'd' || format[p->index] == 'D'
		|| format[p->index] == 'i')
	{
		p->conv = FT_PRINTF_D;
		if (format[p->index] == 'D')
			p->modifier = FT_PRINTF_L;
	}
	else if (format[p->index] == 'o' || format[p->index] == 'O')
	{
		p->conv = FT_PRINTF_O;
		if (format[p->index] == 'O')
			p->modifier = FT_PRINTF_L;
	}
	else if (format[p->index] == 'p')
		p->conv = FT_PRINTF_P;
	else
		ft_pritnf_get_conv2(p, format);
}
