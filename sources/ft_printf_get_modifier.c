/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_modifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 22:17:15 by mapandel          #+#    #+#             */
/*   Updated: 2017/07/18 21:30:57 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_get_modifier(t_printf *p, const char *format)
{
	if (format[p->index] == 'h')
	{
		if (p->modifier == FT_PRINTF_HH)
			p->modifier = FT_PRINTF_HHH;
		else if (p->modifier < FT_PRINTF_HH)
			p->modifier = FT_PRINTF_HH;
	}
	else if (format[p->index] == 'j' && p->modifier < FT_PRINTF_J)
		p->modifier = FT_PRINTF_J;
	else if (format[p->index] == 'z' && p->modifier < FT_PRINTF_Z)
		p->modifier = FT_PRINTF_Z;
	else if (format[p->index] == 'l')
	{
		if (p->modifier == FT_PRINTF_L)
			p->modifier = FT_PRINTF_LL;
		else if (p->modifier < FT_PRINTF_L)
			p->modifier = FT_PRINTF_L;
	}
	++p->index;
}
