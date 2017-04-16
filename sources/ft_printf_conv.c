/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:57:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/16 17:06:33 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_printf_conv(t_printf *p)
{
	int		i;

	i = 0;
	while (i < 6 && !p->error)
		p = p->tab_ptr[i++](p);
	return (p);
}
