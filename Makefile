# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 00:57:23 by rsebasti          #+#    #+#              #
#    Updated: 2024/11/10 14:45:52 by rsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all