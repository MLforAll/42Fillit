# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:07:31 by kdumarai          #+#    #+#              #
#    Updated: 2017/11/14 15:55:25 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GFLAGS = -Wall -Werror -Wextra

SRCS = fillit_main.c \
		fillit_analysis.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C ../Libft
	gcc -c $(SRCS)
	gcc -o $(NAME) $(OBJS) ../Libft/libft.a

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
