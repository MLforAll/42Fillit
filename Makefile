# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 19:26:06 by kdumarai          #+#    #+#              #
#    Updated: 2017/11/24 16:32:18 by kdumarai         ###   ########.fr        #
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
	make -C Libft
	gcc -o $(NAME) $(OBJS) -L Libft -lft

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	make clean -C Libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft
	rm -f $(NAME)

re: fclean all
