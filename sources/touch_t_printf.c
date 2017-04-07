/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_t_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:27:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 14:58:32 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			del_t_printf(t_printf *p)
{
	ft_memdel((void**)&p);
}

void			reset_t_printf(t_printf *p)
{
	p->modifier = FT_PRINTF_NO_MODIFIERS;
	p->conv = FT_PRINTF_WAIT_INPUT;
}

t_printf		*init_t_printf(t_printf *p)
{
	if (!p && !(p = ft_memalloc(sizeof(p))))
		exit (-1);
	reset_t_printf(p);
	p->error = 0;
	p->index = 0;
	p->ret = 0;
	return (p);
}
