# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 17:00:28 by aabouibr          #+#    #+#              #
#    Updated: 2018/12/07 17:24:20 by aabouibr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FRACTOLFILES = *.c

LIBS = libft.a libmlx.a ./myglib/myglib.a
FLAGS = -framework OpenGl -framework AppKit -Wall -Werror -Wextra

all: $(NAME)
$(NAME):
	gcc $(FRACTOLFILES) $(LIBS) $(FLAGS) -o $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
