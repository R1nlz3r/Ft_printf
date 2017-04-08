/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:57:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/08 01:44:55 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_printf_parsing(t_printf *p, const char *format)
{
	while (!(ft_strrchr("sSpdDioOuUxXcC%", format[p->index])))
	{
		if (ft_strrchr("hljz", format[p->index]))
			ft_printf_get_modifier(p, format);
		else if (ft_strrchr("#0-+ ", format[p->index]))
			ft_printf_get_flag(p, format);
		else if (format[p->index] == '.')
			ft_printf_get_precision(p, format);
//		else if (ft_isdigit((int)format[p->index]) && format[p->index] != '0')
//			ft_printf_get_width(p, format);
		else
		{
			p->error = -1;
			return (p);
		}
	}
	ft_printf_get_conv(p, format);
	if (p->conv == FT_PRINTF_WAIT_INPUT)
		p->error = -1;
	++p->index;
	return (p);
}
