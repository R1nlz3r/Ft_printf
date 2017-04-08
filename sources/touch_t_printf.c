/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:27:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/08 20:32:43 by mapandel         ###   ########.fr       */
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
	p->width = -1;
	p->modifier = FT_PRINTF_NO_MODIFIERS;
	p->conv = FT_PRINTF_WAIT_INPUT;
	ft_strdel(&p->conv_ret);
}

static void		init_t_printf_tab_ptr(t_printf *p)
{
	p->tab_ptr[0] = &ft_printf_s;
	//ect..
}

t_printf		*init_t_printf(t_printf *p)
{
	if (!(p = ft_memalloc(sizeof(t_printf)))
		|| !(p->flags = ft_memalloc(sizeof(t_printf_flags)))
		|| !(p->conv_ret = ft_strnew(0)))
		exit(-1);
	init_t_printf_tab_ptr(p);
	reset_t_printf(p);
	p->error = 0;
	p->index = 0;
	p->ret = 0;
	return (p);
}
