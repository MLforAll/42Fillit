# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 19:26:06 by kdumarai          #+#    #+#              #
#    Updated: 2018/04/25 13:50:21 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

SRCS = fillit_analysis.c \
	fillit_main.c \
	fillit_misc.c \
	fillit_solver.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) fillit.h
	make -C libft
	gcc -o $(NAME) $(OBJS) -L libft -lft

%.o: %.c
	gcc $(CFLAGS) -I . -I libft/includes -c $<

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
