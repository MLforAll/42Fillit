# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 19:26:06 by kdumarai          #+#    #+#              #
#    Updated: 2018/07/31 22:38:36 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

SRCS = fillit_analysis.c \
	fillit_main.c \
	fillit_misc.c \
	fillit_solver.c \
	ft_strsplitline.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) fillit.h
	make -C libft
	gcc -o $(NAME) $(OBJS) -L libft -lft

%.o: %.c
	gcc $(CFLAGS) -I . -I libft/includes -c $<

cleanp:
	rm -f $(OBJS)

clean: cleanp
	make clean -C libft

fcleanp: cleanp
	rm -f $(NAME)

fclean: fcleanp
	make fclean -C libft

re: fclean all
