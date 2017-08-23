# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydana <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/23 14:43:34 by ydana             #+#    #+#              #
#    Updated: 2017/08/23 22:49:40 by gbetting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = ft_analyse.c gp_function/ft_fonctions_chiants.c main.c gp_function/ft_reader.c gp_function/ft_main.c

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

arg_exe: re
	    @perl grid_generation.pe 1000 1000 0 > test_1.txt
		    @cat -e test_1.txt
			    @./$(NAME) test_1.txt
				    @rm test_1.txt
pipe_exe: re
	    @perl grid_generation.pe 15 15 0.2 > test_pipe.txt
		    @rm test_pipe.txt
fake_arg_exe_1: re
	    @./$(NAME) "49.xo" "" "     "
fake_arg_exe_2: re
	    @echo "2.ox\n..o.\n..o" > fake_arg_2.txt
		    @./$(NAME) fake_arg_2.txt
			    @cat fake_arg_2.txt
				    @rm fake_arg_2.txt
fake_arg_exe_3: re
	    @touch fake_arg_3.txt
		    @./$(NAME) fake_arg_3.txt
			    @rm fake_arg_3.txt
fake_pipe_exe_1: re
	    @touch fake_pipe_1.txt
		    @cat fake_pipe_1.txt | ./$(NAME)
			    @rm fake_pipe_1.txt
fake_pipe_exe_2: re
	    @echo "2.ox\n..o.\n..o" > fake_pipe_2.txt
		    @cat fake_pipe_2.txt | ./$(NAME)
			    @rm fake_pipe_2.txt
fake_pipe_exe_3:
	    @cat *.o  | ./$(NAME)
