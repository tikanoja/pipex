# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:27:12 by ttikanoj          #+#    #+#              #
#    Updated: 2023/01/14 17:18:27 by tuukka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./pipex.c ft_split.c pipex_utils.c pipex_utils2.c pipex_errors.c \
		pipex_errors2.c ft_split_pipex.c ft_split_utils.c

OBJ = ./pipex.o ft_split.o pipex_utils.o pipex_utils2.o pipex_errors.o \
		pipex_errors2.o ft_split_pipex.o ft_split_utils.o

HEADERS = -I ./includes

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(HEADERS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
