# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 03:03:10 by mapandel          #+#    #+#              #
#    Updated: 2017/04/15 21:19:33 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror -Weverything

#			Sources

SRC =		libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isblank.c \
			libft/ft_iscntrl.c \
			libft/ft_isdigit.c \
			libft/ft_isgraph.c \
			libft/ft_isinf.c \
			libft/ft_islessinf.c \
			libft/ft_islower.c \
			libft/ft_isnan.c \
			libft/ft_isprint.c \
			libft/ft_ispunct.c \
			libft/ft_isspace.c \
			libft/ft_isupper.c \
			libft/ft_isxdigit.c \
			libft/ft_itoa.c \
			libft/ft_lltoabase_signed.c \
			libft/ft_lltoabase_signless.c \
			libft/ft_lltoabase_unsigned.c \
			libft/ft_lstadd.c \
			libft/ft_lstdel.c \
			libft/ft_lstdelone.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_lstnew.c \
			libft/ft_memalloc.c \
			libft/ft_memccpy.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memdel.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl.c \
			libft/ft_putendl_fd.c \
			libft/ft_putllnbr.c \
			libft/ft_putmap.c \
			libft/ft_putnbr.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr.c \
			libft/ft_putstr_fd.c \
			libft/ft_stradd.c \
			libft/ft_stradd_leakless.c \
			libft/ft_strcat.c \
			libft/ft_strccat.c \
			libft/ft_strccmp.c \
			libft/ft_strccpy.c \
			libft/ft_strchr.c \
			libft/ft_strcjoin.c \
			libft/ft_strcjoin_leakless.c \
			libft/ft_strclen.c \
			libft/ft_strclr.c \
			libft/ft_strcmp.c \
			libft/ft_strcpy.c \
			libft/ft_strdel.c \
			libft/ft_strdup.c \
			libft/ft_strequ.c \
			libft/ft_strfill.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strjoin_leakless.c \
			libft/ft_strlcat.c \
			libft/ft_strlen.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \
			libft/ft_strncat.c \
			libft/ft_strncmp.c \
			libft/ft_strncpy.c \
			libft/ft_strnequ.c \
			libft/ft_strnew.c \
			libft/ft_strnstr.c \
			libft/ft_strplugc.c \
			libft/ft_strrchr.c \
			libft/ft_strrev.c \
			libft/ft_strrev_leakless.c \
			libft/ft_strsplit.c \
			libft/ft_strstr.c \
			libft/ft_strsub.c \
			libft/ft_strsub_leakless.c \
			libft/ft_strtolower.c \
			libft/ft_strtoupper.c \
			libft/ft_strtrim.c \
			libft/ft_tabfill.c \
			libft/ft_tabnew.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/get_next_line.c \
			libft/get_next_char.c \
			sources/ft_printf.c \
			sources/touch_t_printf.c \
			sources/ft_printf_display.c \
			sources/ft_printf_parsing.c \
			sources/ft_printf_get_conv.c \
			sources/ft_printf_get_modifier.c \
			sources/ft_printf_get_flags.c \
			sources/ft_printf_get_precision.c \
			sources/ft_printf_get_width.c \
			sources/ft_printf_conv.c \
			sources/ft_printf_s.c \
			sources/ft_printf_d.c \
			sources/ft_printf_o.c \
			sources/ft_printf_u.c \

OBJ =		$(SRC:.c=.o)

INC =		includes

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

.PHONY: all re affcompil clean fclean

$(NAME):
	@make affcompil
	@echo "$(GRE)--::Libftprintf Indextion::--$(DEF)"
	@ar rc $(NAME) $(LIBPATH) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

re: fclean all

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $^

affcompil:
	@echo "$(BLU)--::Libftprintf Compilation::--$(DEF)"
	@make $(OBJ)

#			Clean Rules

clean:
	@echo "$(PUR)--::Libftprintf.a Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Library Delection::--$(DEF)"
	@rm -rf $(NAME)
