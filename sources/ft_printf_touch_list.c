/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_touch_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:21:19 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/23 12:43:34 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf			*ft_printf_iter_list(t_printf *p, int i)
{
	while (p->args && i < p->args->index)
		p->args = p->args->previous;
	while (p->args && i > p->args->index)
		p->args = p->args->next;
	if (!p->args || (p->args && i != p->args->index))
		exit (-1);
	return (p);
}

t_printf			*ft_printf_list_add(t_printf *p)
{
	t_printf_list		*tmp;
	int					index;

	if (!p->args)
	{
		if (!(p->args = ft_memalloc(sizeof(t_printf_list))))
			exit (-1);
		p->args->previous = NULL;
		p->args->next = NULL;
		p->args->index = 0;
		return (p);
	}
	tmp = p->args;
	index = p->args->index + 1;
	if (!(p->args->next = ft_memalloc(sizeof(t_printf_list))))
		exit (-1);
	p->args = p->args->next;
	p->args->previous = tmp;
	p->args->next = NULL;
	p->args->index = index;
	return (p);
}

void			ft_del_t_printf(t_printf *p)
{
	t_printf_list		*tmp;

	p = ft_printf_iter_list(p, 0);
	while (p->args)
	{
		tmp = p->args->next;
		ft_memdel((void**)&p->args);
		p->args = tmp;
	}
	ft_memdel((void**)&p->flags);
	ft_memdel((void**)&p);
}

t_printf		*ft_init_t_printf_flags(t_printf *p)
{
	p->flags->sharp = 0;
	p->flags->zero = 0;
	p->flags->neg = 0;
	p->flags->space = 0;
	p->flags->positive = 0;
	p->flags->apostrophe = 0;
	return (p);
}

t_printf		*ft_init_t_printf(t_printf *p)
{
	if (!p && !(p = ft_memalloc(sizeof(t_printf))))
		exit (-1);
	if (!(p->flags = ft_memalloc(sizeof(t_printf_flags))))
		exit (-1);
	p = ft_init_t_printf_flags(p);
	p->i = 0;
	p->ret = 0;
	return (p);
}
