/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:58:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/29 15:09:48 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

#define C_BOLD						"\033[1m"
#define C_RESET_BOLD				"\033[21m"
#define C_DIM						"\033[2m"
#define C_RESET_DIM					"\033[22m"
#define C_UNDERLINE					"\033[4m"
#define C_RESET_UNDERLINE			"\033[24m"
#define C_BLINK						"\033[5m"
#define C_RESET_BLINK				"\033[25m"
#define C_REVERSE					"\033[7m"
#define C_RESET_REVERSE				"\033[27m"
#define C_HIDDEN					"\033[8m"
#define C_RESET_HIDDEN				"\033[28m"
#define C_EOC						"\033[0m"
#define C_BLACK						"\033[30m"
#define C_RED						"\033[31m"
#define C_GREEN						"\033[32m"
#define C_YELLOW					"\033[33m"
#define C_BLUE						"\033[34m"
#define C_MAGENTA					"\033[35m"
#define C_CYAN						"\033[36m"
#define C_LIGHT_GRAY				"\033[37m"
#define C_DARK_GRAY					"\033[90m"
#define C_LIGHT_RED					"\033[91m"
#define C_LIGHT_GREEN				"\033[92m"
#define C_LIGHT_YELLOW				"\033[93m"
#define C_LIGHT_BLUE				"\033[94m"
#define C_LIGHT_MAGENTA				"\033[95m"
#define C_LIGHT_CYAN				"\033[96m"
#define C_WHITE						"\033[97m"
#define C_RESET_COLOR				"\033[39m"
#define C_BACKGROUND_BLACK			"\033[40m"
#define C_BACKGROUND_RED			"\033[41m"
#define C_BACKGROUND_GREEN			"\033[42m"
#define C_BACKGROUND_YELLOW			"\033[43m"
#define C_BACKGROUND_BLUE			"\033[44m"
#define C_BACKGROUND_MAGENTA		"\033[45m"
#define C_BACKGROUND_CYAN			"\033[46m"
#define C_BACKGROUND_LIGHT_GRAY		"\033[47m"
#define C_BACKGROUND_DARK_GRAY		"\033[100m"
#define C_BACKGROUND_LIGHT_RED		"\033[101m"
#define C_BACKGROUND_LIGHT_GREEN	"\033[102m"
#define C_BACKGROUND_LIGHT_YELLOW	"\033[103m"
#define C_BACKGROUND_LIGHT_BLUE		"\033[104m"
#define C_BACKGROUND_LIGHT_MAGENTA	"\033[105m"
#define C_BACKGROUND_LIGHT_CYAN		"\033[106m"
#define C_BACKGROUND_WHITE			"\033[107m"
#define C_RESET_BACKGROUND_COLOR	"\033[49m"

/*
**	Types:
**		PRINTF_STAR	-> int
**		wint_t		-> int
**		wchar_t*	-> int*
**		intmax_t	-> long
**		ptrdiff_t	-> long
**		quad_t		-> long long
*/

typedef struct				s_printf_flags
{
	short					sharp;
	short					zero;
	short					neg;
	short					space;
	short					positive;
	short					apostrophe;
}							t_printf_flags;

enum e_printf_modifier
{
	PRINTF_NO_MODIFIERS,
	PRINTF_H,
	PRINTF_HH,
	PRINTF_J,
	PRINTF_L,
	PRINTF_LL,
	PRINTF_LLL,
	PRINTF_Q,
	PRINTF_T,
	PRINTF_Z,
};

enum e_printf_conv
{
	PRINTF_A,
	PRINTF_B,
	PRINTF_C,
	PRINTF_D,
	PRINTF_E,
	PRINTF_EE,
	PRINTF_F,
	PRINTF_G,
	PRINTF_K,
	PRINTF_N,
	PRINTF_O,
	PRINTF_P,
	PRINTF_R,
	PRINTF_S,
	PRINTF_U,
	PRINTF_X,
	PRINTF_XX,
	PRINTF_PERCENT,
	PRINTF_BRACKET
};

typedef struct				s_printf_list
{
	void					*arg;
	struct s_printf_list	*next;
	struct s_printf_list	*previous;
	char					pad_0[4];
	int						index;
}							t_printf_list;

typedef struct				s_printf
{
	t_printf_list			*args;
	t_printf_flags			*flags;
	enum e_printf_modifier	modifier;
	enum e_printf_conv		conv;
	int						precision;
	int						width;
	int						index;
	int						i;
	int						ret;
	char					pad_0[4];
	va_list					list;
}							t_printf;

int							ft_printf(const char *format, ...);

t_printf					*ft_printf_list_add(t_printf *p);
t_printf					*ft_printf_iter_list(t_printf *p, int i);
void						ft_del_t_printf(t_printf *p);
t_printf					*ft_init_t_printf_flags(t_printf *p);
t_printf					*ft_init_t_printf(t_printf *p);

t_printf					*ft_printf_get_flags(t_printf *p, const char *format);
t_printf					*ft_printf_get_modifier(t_printf *p, const char *format);
t_printf					*ft_printf_get_conv(t_printf *p, const char *format);

t_printf					*ft_printf_search_args(t_printf *p, const char *format);
t_printf					*ft_printf_save_arg(t_printf *p);

t_printf					*ft_printf_display(t_printf *p, const char *format);

void						ft_printf_color(t_printf *p, const char *format);

#endif
