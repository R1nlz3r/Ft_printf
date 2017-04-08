/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_modifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 22:17:15 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 23:03:54 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_get_modifier(t_printf *p, const char *format)
{
	if (format[p->index] == 'h')
	{
		p->modifier = FT_PRINTF_H;
		if (format[p->index + 1] == 'h' && ++p->index)
			p->modifier = FT_PRINTF_HH;
	}
	else if (format[p->index] == 'j')
		p->modifier = FT_PRINTF_J;
	else if (format[p->index] == 'l')
	{
		p->modifier = FT_PRINTF_L;
		if (format[p->index + 1] == 'l' && ++p->index)
			p->modifier = FT_PRINTF_LL;
	}
	else if (format[p->index] == 'z')
		p->modifier = FT_PRINTF_Z;
	++p->index;
}
