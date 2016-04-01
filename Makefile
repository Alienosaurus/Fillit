# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 10:24:38 by dalexand          #+#    #+#              #
#    Updated: 2016/03/06 18:30:38 by dalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Wextra

INCLUDES = -I ./libft

HEADERS = libft/libft.h fillit.h

SRC = $(wildcard *.c)

SRC_LIBFT = $(wildcard libft/*.c)

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	gcc -o $(NAME) $(SRC) $(INCLUDES) -L./libft -lft

libft/libft.a: $(OBJ_LIBFT)
	ar rc libft/libft.a $(OBJ_LIBFT)
	
%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_LIBFT) libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean clean all

OBJ_EXCPECT_MAIN = $(filter-out main.o, $(OBJ))
SRC_TEST = $(wildcard test/*.test.c)
EXECUTABLE_TEST = $(SRC_TEST:test/%.test.c=test/%.pink)

test/%.pink: test/%.test.c $(HEADER) $(OBJ_EXCPECT_MAIN) libft/libft.a
	gcc  $< $(OBJ_EXCPECT_MAIN) $(INCLUDES) -L./libft -lft -o $@
	$@

test: $(EXECUTABLE_TEST)

