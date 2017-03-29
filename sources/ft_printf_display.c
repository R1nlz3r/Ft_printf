/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:43:55 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/24 11:41:20 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf		*ft_printf_parsing_display(t_printf *p,
	const char *format)
{
	while (format[p->i]
		&& !(ft_strrchr("%aAbcCdDeEfFgGiknoOpruUxX{", format[p->i])))
	{
		if (!(ft_strrchr("hjlqtz", format[p->i])))
			p = ft_printf_get_modifier(p, format);
		else if (!(ft_strrchr("#- +'", format[p->i])))
			p = ft_printf_get_flags(p, format);
		else if (!ft_strrchr(".1234567890$", format[p->i]))
		{
			ft_putchar(format[p->i]);
			++p->ret;
			return (NULL);
		}
		++p->i;
	}
	if (!format[p->i])
		(void)p;
		//go display
	return (p);
}

t_printf			*ft_printf_display(t_printf *p, const char *format)
{
	t_printf	*tmp;

	while (format[p->i])
	{
		if (format[p->i] == '%')
		{
			++p->i;
			if ((tmp = ft_printf_parsing_display(p, format)))
				p = tmp;
		}
		else
		{
			++p->ret;
			ft_putchar(format[p->i]);
		}
		++p->i;
	}
	return (p);
}
