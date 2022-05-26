# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 21:56:03 by rde-lima          #+#    #+#              #
#    Updated: 2022/05/26 17:32:05 by rde-lima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf_utils.c ft_printf.c

CC = clang
FLAGS = -Wall -Werror -Wextra
INC = -Iinclude

SRC_DIR = src
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiled '$(NAME)' successfully!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling '$<' with flags: '$(FLAGS)'"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "Compiled '$@' successfully!"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned '$(OBJ_DIR)' successfully!"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned '$(NAME)' successfully!"

re: fclean all

debug: FLAGS += -fsanitize=address -fno-omit-frame-pointer -g3
debug: fclean all

.PHONY: all clean fclean re debug
