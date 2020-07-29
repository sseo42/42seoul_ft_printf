# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sseo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 12:00:58 by sseo              #+#    #+#              #
#    Updated: 2020/06/14 12:33:43 by sseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAMEA = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c			\
	   ft_printf_branch.c	\
	   ft_printf_func.c		\
	   ft_printf_c.c		\
	   ft_printf_f.c		\
	   ft_printf_e.c		\
	   ft_printf_g.c		\
	   ft_printf_i.c		\
	   ft_printf_p.c		\
	   ft_printf_s.c		\
	   ft_printf_ws.c		\
	   ft_printf_u.c		\
	   ft_printf_x.c		\
	   ft_sub_func.c		\
	   ft_appender.c		\
	   ft_d2fixed.c			\
	   ft_mantissa.c		\
	   ft_math.c

OBJS = $(SRCS:.c=.o)

INC = ft_print.h

LIB_DIR = libft

$(NAME): $(OBJS)
	cd $(LIB_DIR); $(MAKE) bonus
	cd $(LIB_DIR); cp $(NAMEA) ../$(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(NAMEA)
	rm -f $(OBJS)
	cd $(LIB_DIR); $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
