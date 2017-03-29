/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_additional_fields.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:39:02 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/23 01:10:04 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*ft_printf_get_flags(t_printf *p, const char *format)
{
	if (format[p->i] == '#')
		p->flags->sharp = 1;
	else if (format[p->i] == '0')
		p->flags->zero = 1;
	else if (format[p->i] == '-')
		p->flags->neg = 1;
	else if (format[p->i] == ' ')
		p->flags->space = 1;
	else if (format[p->i] == '+')
		p->flags->positive = 1;
	else if (format[p->i] == '\'')
		p->flags->apostrophe = 1;
	else
		exit (-1);
	return (p);
}

t_printf			*ft_printf_get_modifier(t_printf *p, const char *format)
{
	if (format[p->i] == 'h')
	{
		p->modifier = PRINTF_H;
		if (format[p->i + 1] == 'h' && ++p->i)
			p->modifier = PRINTF_HH;
	}
	else if (format[p->i] == 'j')
		p->modifier = PRINTF_J;
	else if (format[p->i] == 'l')
	{
		p->modifier = PRINTF_L;
		if (format[p->i + 1] == 'l' && ++p->i)
			p->modifier = PRINTF_LL;
	}
	else if (format[p->i] == 'L')
		p->modifier = PRINTF_LLL;
	else if (format[p->i] == 'q')
		p->modifier = PRINTF_Q;
	else if (format[p->i] == 't')
		p->modifier = PRINTF_T;
	else if (format[p->i] == 'z')
		p->modifier = PRINTF_Z;
	return (p);
}

static t_printf		*ft_printf_get_conv3(t_printf *p, const char *format)
{
	if (format[p->i] == 'u' || format[p->i] == 'U')
	{
		p->conv = PRINTF_U;
		if (format[p->i] == 'U')
			p->modifier = PRINTF_L;
	}
	else if (format[p->i] == 'x')
		p->conv = PRINTF_X;
	else if (format[p->i] == 'X')
		p->conv = PRINTF_XX;
	else if (format[p->i] == '%')
		p->conv = PRINTF_PERCENT;
	else if (format[p->i] == '{')
		p->conv = PRINTF_BRACKET;
	else
		exit (-1);
	return (p);
}

static t_printf		*ft_pritnf_get_conv2(t_printf *p, const char *format)
{
	if (format[p->i] == 'g' || format[p->i] == 'G')
		p->conv = PRINTF_G;
	else if (format[p->i] == 'k')
		p->conv = PRINTF_K;
	else if (format[p->i] == 'n')
		p->conv = PRINTF_N;
	else if (format[p->i] == 'o' || format[p->i] == 'O')
	{
		p->conv = PRINTF_O;
		if (format[p->i] == 'O')
			p->modifier = PRINTF_L;
	}
	else if (format[p->i] == 'p')
		p->conv = PRINTF_P;
	else if (format[p->i] == 'r')
		p->conv = PRINTF_R;
	else if (format[p->i] == 's' || format[p->i] == 'S')
	{
		p->conv = PRINTF_S;
		if (format[p->i] == 'S')
			p->modifier = PRINTF_L;
	}
	else
		p = ft_printf_get_conv3(p, format);
	return (p);
}

t_printf			*ft_printf_get_conv(t_printf *p, const char *format)
{
	if (format[p->i] == 'a' || format[p->i] == 'A')
		p->conv = PRINTF_A;
	else if (format[p->i] == 'b')
		p->conv = PRINTF_B;
	else if (format[p->i] == 'c' || format[p->i] == 'C')
	{
		p->conv = PRINTF_C;
		if (format[p->i] == 'C')
			p->modifier = PRINTF_L;
	}
	else if (format[p->i] == 'd' || format[p->i] == 'D' || format[p->i] == 'i')
	{
		p->conv = PRINTF_D;
		if (format[p->i] == 'D')
			p->modifier = PRINTF_L;
	}
	else if (format[p->i] == 'e')
		p->conv = PRINTF_E;
	else if (format[p->i] == 'E')
		p->conv = PRINTF_EE;
	else if (format[p->i] == 'f' || format[p->i] == 'F')
		p->conv = PRINTF_F;
	else
		p = ft_pritnf_get_conv2(p, format);
	return (p);
}
