/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 05:08:19 by mapandel          #+#    #+#             */
/*   Updated: 2017/07/18 22:01:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t		*ft_printf_cc_width(t_printf *p, wchar_t *str)
{
	size_t		tmp;
	wchar_t		*str2;
	wchar_t		*buf;

	if (p->width != -1 && (size_t)p->width > ft_wstrlenuni(str)
		&& (tmp = (size_t)p->width - ft_wstrlenuni(str)))
	{
		if (!str[0])
			--tmp;
		if (!(str2 = ft_wstrnew(tmp))
			&& (p->error = -1))
			return (str);
		if (p->flags->zero && !p->flags->less)
			str2 = ft_wstrfill(str2, L'0', tmp);
		else
			str2 = ft_wstrfill(str2, L' ', tmp);
		if (p->flags->less)
			buf = ft_wstrjoin(str, str2);
		else
			buf = ft_wstrjoin(str2, str);
		ft_wstrdel(&str2);
		ft_wstrdel(&str);
		str = buf;
	}
	return (str);
}

t_printf			*ft_printf_cc(t_printf *p)
{
	wchar_t		*str;
	wchar_t		tmp;

	if (!(p->conv == FT_PRINTF_C && p->modifier == FT_PRINTF_L))
		return (p);
	tmp = (wchar_t)va_arg(p->ap, wint_t);
	if ((tmp < 0 || (MB_CUR_MAX != 4 && tmp > 255) || (MB_CUR_MAX == 4
		&& (tmp > 1114111 || (tmp > 55295 && tmp < 57344))))
		&& (p->error = 1))
		return (p);
	str = ft_wstrnew(1);
	str[0] = tmp;
	str = ft_printf_cc_width(p, str);
	if (p->error)
		return (p);
	if (!p->flags->less)
		ft_putwstr(str);
	if (!tmp && ++p->ret)
		ft_putwchar(tmp);
	if (p->flags->less)
		ft_putwstr(str);
	p->ret += ft_wstrlenuni(str);
	ft_wstrdel(&str);
	return (p);
}
