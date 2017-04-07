/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:57:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 15:55:03 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_printf_parsing(t_printf *p, const char *format)
{
	while (!(ft_strrchr("sSpdDioOuUxXcC%", format[p->index])))
	{
		if (ft_strrchr("hljz", format[p->index]))
			ft_printf_get_modifier(p, format);
		//add elements de parsing
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
