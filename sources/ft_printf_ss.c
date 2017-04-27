/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:34:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/27 02:21:16 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t		*ft_printf_ss_precision(t_printf *p, wchar_t *str)
{
	if (p->precision != -1 && (size_t)p->precision < ft_wstrlenuni(str))
	{
		if (!(str = ft_wstrsub_leakless(str, 0, (size_t)p->precision)))
		{
			p->error = -1;
			return (str);
		}
	}
	return (str);
}

static wchar_t		*ft_printf_ss_width(t_printf *p, wchar_t *str)
{
	size_t		tmp;
	wchar_t		*str2;
	wchar_t		*buf;

	if (p->width != -1 && (size_t)p->width > ft_wstrlenuni(str)
		&& (tmp = (size_t)p->width - ft_wstrlenuni(str)))
	{
		if (!(str2 = ft_wstrnew(tmp)) && (p->error = -1))
			return (str);
		if (p->flags->zero && !p->flags->less)
			str2 = ft_wstrfill(str2, L'0', tmp);
		else
			str2 = ft_wstrfill(str2, L' ', tmp);
		if (p->flags->less)
			buf = ft_wstrjoin(str, str2);
		else
			buf = ft_wstrjoin(str2, str);
		if (!buf && (p->error = -1))
			return (str);
		ft_wstrdel(&str2);
		ft_wstrdel(&str);
		str = buf;
	}
	return (str);
}

t_printf			*ft_printf_ss(t_printf *p)
{
	wchar_t		*str;
	wchar_t		*tmp;

	if (!(p->conv == FT_PRINTF_S && p->modifier == FT_PRINTF_L))
		return (p);
	if (MB_CUR_MAX != 4 && (p->ret = -1))
	{
		p->error = -1;
		return (p);
	}
	if (!(tmp = va_arg(p->ap, wchar_t*)))
	{
		if (!(str = ft_wstrdup(L"(null)")) && (p->error = -1))
			return (p);
	}
	else if (!(str = ft_wstrdup(tmp)) && (p->error = -1))
		return (p);
	str = ft_printf_ss_precision(p, str);
	if (p->error)
		return (p);
	str = ft_printf_ss_width(p, str);
	if (p->error)
		return (p);
	ft_putwstr(str);
	p->ret += ft_wstrlenuni(str);
	ft_wstrdel(&str);
	return (p);
}
