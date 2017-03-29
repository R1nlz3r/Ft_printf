/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:57:46 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/24 00:03:42 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	t_printf		*p;
	int				ret;

	p = NULL;
	if (!format)
		exit (-1);
	p = ft_init_t_printf(p);
	va_start(p->list, format);
	p = ft_printf_search_args(p, format);
	p->i = 0;
	p = ft_printf_display(p, format);
	ret = p->ret;
	va_end(p->list);
	ft_del_t_printf(p);
	return (ret);
}
