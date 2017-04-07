/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:19:56 by mapandel          #+#    #+#             */
/*   Updated: 2017/04/07 14:57:06 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

enum e_printf_modifier
{
	FT_PRINTF_NO_MODIFIERS,
	FT_PRINTF_H,
	FT_PRINTF_HH,
	FT_PRINTF_J,
	FT_PRINTF_L,
	FT_PRINTF_LL,
	FT_PRINTF_Z
};

enum e_printf_conv
{
	FT_PRINTF_WAIT_INPUT,
	FT_PRINTF_C,
	FT_PRINTF_D,
	FT_PRINTF_O,
	FT_PRINTF_P,
	FT_PRINTF_S,
	FT_PRINTF_U,
	FT_PRINTF_X,
	FT_PRINTF_XX,
	FT_PRINTF_PERCENT
};

typedef struct					s_printf
{
	va_list						ap;
	int							error;
	int							index;
	int							ret;
	enum e_printf_modifier		modifier;
	enum e_printf_conv			conv;
	char						pad_0[4];
}								t_printf;

int				ft_printf(char *format, ...);
t_printf		*init_t_printf(t_printf *p);
void			reset_t_printf(t_printf *p);
void			del_t_printf(t_printf *p);
void			ft_printf_display(t_printf *p, const char *format);
t_printf		*ft_printf_parsing(t_printf *p, const char *format);
void			ft_printf_get_conv(t_printf *p, const char *format);
void			ft_printf_get_modifier(t_printf *p, const char *format);
#endif
