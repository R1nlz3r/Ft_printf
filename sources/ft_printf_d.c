/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:21:19 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/10 17:54:08 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_printf_d_get_arg(t_printf *p)
{
	long long		ret;

	ret = 0;
	if (p->modifier == FT_PRINTF_NO_MODIFIERS)
		ret = va_arg(p->ap, int);
	else if (p->modifier == FT_PRINTF_H)
		ret = (long long)(short)va_arg(p->ap, int);
	else if (p->modifier == FT_PRINTF_HH)
		ret = (long long)(signed char)va_arg(p->ap, int);
	else if (p->modifier == FT_PRINTF_J)
		ret = va_arg(p->ap, intmax_t);
	else if (p->modifier == FT_PRINTF_L)
		ret = va_arg(p->ap, long);
	else if (p->modifier == FT_PRINTF_LL)
		ret = va_arg(p->ap, long long);
	else if (p->modifier == FT_PRINTF_Z)
		ret = (long long)va_arg(p->ap, size_t);
	return (ret);
}

static t_printf		*ft_printf_d_precision(t_printf *p, long long tmp)
{
	size_t		tmp2;
	char		*str;
	char		*buf;

	if (p->precision != -1 && !p->precision && !tmp)
	{
		if (!(str = ft_strnew(0)) && (p->error = -1))
			return (p);
		ft_strdel(&p->conv_ret);
		p->conv_ret = str;
	}
	else if (p->precision != -1 && (size_t)p->precision > ft_strlen(p->conv_ret)
		&& (tmp2 = (size_t)p->precision - ft_strlen(p->conv_ret)))
	{
		if (!(str = ft_strnew(tmp2)) && (p->error = -1))
			return (p);
		str = ft_strfill(str, '0', tmp2);
		buf = ft_strjoin(str, p->conv_ret);
		if (!buf && (p->error = -1))
			return (p);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

static t_printf		*ft_printf_d_width(t_printf *p)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->width != -1 && (size_t)p->width > ft_strlen(p->conv_ret)
		&& (tmp = (size_t)p->width - ft_strlen(p->conv_ret)))
	{
		if (!(str = ft_strnew(tmp)) && (p->error = -1))
			return (p);
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

static t_printf		*ft_printf_d_flags(t_printf *p)
{
	char		*str;
	char		*buf;

	str = NULL;
	buf = NULL;
	if ((!(str = ft_strnew(1))) && (p->error = -1))
		return (p);
	if (p->flags->plus)
	{
		str[0] = '+';
		buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
	}
	else if (p->flags->space)
	{
		str[0] = ' ';
		buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
	}
	ft_strdel(&str);
	return (p);
}

t_printf			*ft_printf_d(t_printf *p)
{
	long long		tmp;

	if (!(p->conv == FT_PRINTF_D))
		return (p);
	if (!(p->conv_ret = ft_itoabase_signed((tmp = ft_printf_d_get_arg(p)), 10))
		&& (p->error = -1))
		return (p);
	p = ft_printf_d_precision(p, tmp);
	if (p->error)
		return (p);
	if (tmp >= 0)
		p = ft_printf_d_flags(p);
	if (p->error)
		return (p);
	p = ft_printf_d_width(p);
	if (p->error)
		return (p);
	ft_putstr(p->conv_ret);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
