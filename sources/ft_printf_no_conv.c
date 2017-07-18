/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:38:11 by mapandel          #+#    #+#             */
/*   Updated: 2017/07/18 22:09:59 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*ft_printf_width(t_printf *p)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->width != -1 && (size_t)p->width > 1
		&& (tmp = (size_t)p->width - 1))
	{
		str = ft_strnew(tmp);
		if (p->flags->zero && (p->precision == -1 || !p->precision)
			&& !p->flags->less)
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

t_printf			*ft_printf_no_conv(t_printf *p)
{
	if (!(p->conv == FT_PRINTF_NO_MODIFIERS))
		return (p);
	if (!(p->conv_ret = ft_strnew(1))
		&& (p->error = -1))
		return (p);
	p->conv_ret[0] = p->tmpchar;
	p = ft_printf_width(p);
	if (p->error)
		return (p);
	ft_putstr(p->conv_ret);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
