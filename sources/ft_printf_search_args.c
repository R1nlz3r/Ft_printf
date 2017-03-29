/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_search_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:47:00 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/24 11:36:16 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_printf_save_arg(t_printf *p)
{
	p = ft_printf_list_add(p);
	p->args->arg = va_arg(p->list, void*);
	return (p);
}

static t_printf		*ft_printf_parsing_conv_modifiers(t_printf *p,
	const char *format)
{
	while (format[p->i]
		&& !(ft_strrchr("%aAbcCdDeEfFgGiknoOpruUxX{", format[p->i])))
	{
		if (format[p->i] == '*')
			p = ft_printf_save_arg(p);
		else if (!ft_strrchr("hjlqtz.1234567890$#- +'", format[p->i]))
			return (NULL);
		++p->i;
	}
	if (!format[p->i])
		return (NULL);
	if (!(format[p->i] == '%' || format[p->i] == '{'))
		p = ft_printf_save_arg(p);
	++p->i;
	return (p);
}

t_printf			*ft_printf_search_args(t_printf *p, const char *format)
{
	t_printf	*tmp;

	while (format[p->i])
	{
		if (format[p->i++] == '%')
		{
			if ((tmp = ft_printf_parsing_conv_modifiers(p, format)))
				p = tmp;
		}
	}
	return (p);
}
