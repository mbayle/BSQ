# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydana <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/23 14:43:34 by ydana             #+#    #+#              #
#    Updated: 2017/08/23 22:02:57 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = ft_analyse.c ft_fonctions_chiants.c main.c ft_reader.c ft_main.c

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(FLAGS) $(OBJECTS)

%.o: %.c 
	cc -o $@ -c $^ $(FLAGS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: clean all
