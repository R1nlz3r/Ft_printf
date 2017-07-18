/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:54:42 by mapandel          #+#    #+#             */
/*   Updated: 2017/07/18 21:57:02 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*ft_printf_c_width(t_printf *p)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->width != -1 && (size_t)p->width > 1 && (tmp = (size_t)p->width - 1))
	{
		if (!(str = ft_strnew(tmp))
			&& (p->error = -1))
			return (p);
		if (p->flags->zero && !p->flags->less)
			str = ft_strfill(str, '0', tmp);
		else
			str = ft_strfill(str, ' ', tmp);
		if (p->flags->less)
			buf = ft_strjoin(p->conv_ret, str);
		else
			buf = ft_strjoin(str, p->conv_ret);
		if (!buf && (p->error = -1))
			return (p);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

t_printf			*ft_printf_c(t_printf *p)
{
	char	arg;

	if (!(p->conv == FT_PRINTF_C && p->modifier != FT_PRINTF_L))
		return (p);
	arg = (char)va_arg(p->ap, int);
	if (!(p->conv_ret = ft_strnew(1))
		&& (p->error = -1))
		return (p);
	p->conv_ret[0] = arg;
	p = ft_printf_c_width(p);
	if (p->error)
		return (p);
	if (!p->flags->less)
		ft_putstr(p->conv_ret);
	if (!arg && ++p->ret)
		ft_putchar(arg);
	if (p->flags->less)
		ft_putstr(p->conv_ret);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
