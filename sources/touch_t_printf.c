/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:27:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 17:11:12 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			del_t_printf(t_printf *p)
{
	ft_memdel((void**)&p->flags);
	ft_memdel((void**)&p);
}

void			reset_t_printf(t_printf *p)
{
	p->flags->sharp = 0;
	p->flags->zero = 0;
	p->flags->less = 0;
	p->flags->space = 0;
	p->flags->plus = 0;
	p->flags->sharp = 0;
	p->flags->apostrophe = 0;
	p->precision = -1;
	p->modifier = FT_PRINTF_NO_MODIFIERS;
	p->conv = FT_PRINTF_WAIT_INPUT;
}

t_printf		*init_t_printf(t_printf *p)
{
	if (!(p = ft_memalloc(sizeof(t_printf)))
		|| !(p->flags = ft_memalloc(sizeof(t_printf_flags))))
		exit (-1);
	reset_t_printf(p);
	p->error = 0;
	p->index = 0;
	p->ret = 0;
	return (p);
}
