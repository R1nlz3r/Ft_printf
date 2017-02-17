/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:09:21 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/16 21:22:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    ft_printf_color_4(const char *format)
{
  if (ft_strnstr(format, "background_magenta", 18))
    ft_putstr(C_BACKGROUND_MAGENTA);
  else if (ft_strnstr(format, "background_cyan", 15))
    ft_putstr(C_BACKGROUND_CYAN);
  else if (ft_strnstr(format, "background_light_gray", 21))
    ft_putstr(C_BACKGROUND_LIGHT_GRAY);
  else if (ft_strnstr(format, "background_dark_gray", 20))
    ft_putstr(C_BACKGROUND_DARK_GRAY);
  else if (ft_strnstr(format, "background_light_red", 20))
    ft_putstr(C_BACKGROUND_LIGHT_RED);
  else if (ft_strnstr(format, "background_light_green", 22))
    ft_putstr(C_BACKGROUND_LIGHT_GREEN);
  else if (ft_strnstr(format, "background_light_yellow", 23))
    ft_putstr(C_BACKGROUND_LIGHT_YELLOW);
  else if (ft_strnstr(format, "background_light_blue", 21))
    ft_putstr(C_BACKGROUND_LIGHT_BLUE);
  else if (ft_strnstr(format, "background_light_magenta", 24))
    ft_putstr(C_BACKGROUND_LIGHT_MAGENTA);
  else if (ft_strnstr(format, "background_light_cyan", 21))
    ft_putstr(C_BACKGROUND_LIGHT_CYAN);
  else if (ft_strnstr(format, "background_white", 16))
    ft_putstr(C_BACKGROUND_WHITE);
  else if (ft_strnstr(format, "reset_background_color", 22))
    ft_putstr(C_RESET_BACKGROUND_COLOR);
  else
    exit(0);
}

static void    ft_printf_color_3(const char *format)
{
  if (ft_strnstr(format, "light_green", 11))
    ft_putstr(C_LIGHT_GREEN);
  else if (ft_strnstr(format, "light_yellow", 12))
    ft_putstr(C_LIGHT_YELLOW);
  else if (ft_strnstr(format, "light_blue", 10))
    ft_putstr(C_LIGHT_BLUE);
  else if (ft_strnstr(format, "light_megenta", 13))
    ft_putstr(C_LIGHT_MAGENTA);
  else if (ft_strnstr(format, "light_cyan", 10))
    ft_putstr(C_LIGHT_CYAN);
  else if (ft_strnstr(format, "white", 5))
    ft_putstr(C_WHITE);
  else if (ft_strnstr(format, "reset_color", 11))
    ft_putstr(C_RESET_COLOR);
  else if (ft_strnstr(format, "background_black", 16))
    ft_putstr(C_BACKGROUND_BLACK);
  else if (ft_strnstr(format, "background_red", 14))
    ft_putstr(C_BACKGROUND_RED);
  else if (ft_strnstr(format, "background_green", 16))
    ft_putstr(C_BACKGROUND_GREEN);
  else if (ft_strnstr(format, "background_yellow", 17))
    ft_putstr(C_BACKGROUND_YELLOW);
  else if (ft_strnstr(format, "background_blue", 15))
    ft_putstr(C_BACKGROUND_BLUE);
  else
    ft_printf_color_4(format);
}

static void    ft_printf_color_2(const char *format)
{
  if (ft_strnstr(format, "reset_hidden", 12))
    ft_putstr(C_RESET_BOLD);
  else if (ft_strnstr(format, "eoc", 16))
    ft_putstr(C_EOC);
  else if (ft_strnstr(format, "black", 5))
    ft_putstr(C_BLACK);
  else if (ft_strnstr(format, "red", 3))
    ft_putstr(C_RED);
  else if (ft_strnstr(format, "green", 5))
    ft_putstr(C_GREEN);
  else if (ft_strnstr(format, "yellow", 6))
    ft_putstr(C_YELLOW);
  else if (ft_strnstr(format, "blue", 4))
    ft_putstr(C_BLUE);
  else if (ft_strnstr(format, "magenta", 7))
    ft_putstr(C_MAGENTA);
  else if (ft_strnstr(format, "cyan", 4))
    ft_putstr(C_CYAN);
  else if (ft_strnstr(format, "light_gray", 10))
    ft_putstr(C_LIGHT_GRAY);
  else if (ft_strnstr(format, "dark_gray", 9))
    ft_putstr(C_DARK_GRAY);
  else if (ft_strnstr(format, "light_red", 9))
    ft_putstr(C_LIGHT_RED);
  else
    ft_printf_color_3(format);
}

void    ft_printf_color(t_printf *print, const char *format)
{
  if (ft_strnstr(format, "bold", 4))
    ft_putstr(C_BOLD);
  else if (ft_strnstr(format, "reset_bold", 10))
    ft_putstr(C_RESET_BOLD);
  else if (ft_strnstr(format, "dim", 3))
    ft_putstr(C_DIM);
  else if (ft_strnstr(format, "reset_dim", 9))
    ft_putstr(C_RESET_DIM);
  else if (ft_strnstr(format, "underline", 9))
    ft_putstr(C_UNDERLINE);
  else if (ft_strnstr(format, "reset_underline", 15))
    ft_putstr(C_RESET_UNDERLINE);
  else if (ft_strnstr(format, "blink", 5))
    ft_putstr(C_BLINK);
  else if (ft_strnstr(format, "reset_blink", 11))
    ft_putstr(C_RESET_BLINK);
  else if (ft_strnstr(format, "reverse", 7))
    ft_putstr(C_REVERSE);
  else if (ft_strnstr(format, "reset_reverse", 13))
    ft_putstr(C_RESET_REVERSE);
  else if (ft_strnstr(format, "hidden", 6))
    ft_putstr(C_HIDDEN);
  else
    ft_printf_color_2(format);
  print->i += ft_strclen(format, '}') + 1;
}
