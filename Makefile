# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 16:09:31 by ayzapata          #+#    #+#              #
#    Updated: 2020/01/02 15:22:00 by ayzapata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
		ft_printf.c \
		ft_find_flags.c \
		ft_converted_value_length.c \
		ft_print_d.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_print_p.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_pct.c

INCLUDE = ft_printf.h

OBJS = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./libft/
			cp ./libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
			gcc $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)
		make clean -C ./libft/

fclean : clean
		rm -f $(NAME)
		make fclean -C ./libft/

re : fclean all

.PHONY: re, clean, fclean, all

