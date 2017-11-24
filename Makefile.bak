# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:07:31 by kdumarai          #+#    #+#              #
#    Updated: 2017/11/18 00:00:47 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = fillit_main.c \
		fillit_analysis.c \
		fillit_solver.c \
		fillit_misc.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	gcc -c $(SRCS)
	gcc -o $(NAME) $(OBJS) libft/libft.a

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
