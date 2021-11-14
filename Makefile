# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 21:56:03 by rde-lima          #+#    #+#              #
#    Updated: 2021/10/27 22:03:21 by rde-lima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf_utils.c \
		ft_printf.c
FLAGS =	-Wall -Werror -Wextra
OBJ :=	$(SRC:%.c=%.o)
CC =	clang

all: $(NAME)

$(OBJ): %.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiled $< successfully!"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Compiled $(NAME) successfully!"

clean:
	@rm -rf $(OBJ)
	@echo "Clean done successfully!"

fclean: clean
	@rm -f $(NAME)
	@echo "Fclean done successfully!"

re: fclean all

.PHONY: all clean fclean re

