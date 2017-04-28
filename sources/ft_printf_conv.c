/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:57:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/27 06:25:33 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_printf_conv(t_printf *p)
{
	int		i;

	i = 0;
	while (i < 11 && !p->error)
		p = p->tab_ptr[i++](p);
	return (p);
}
