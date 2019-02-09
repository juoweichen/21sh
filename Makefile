# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2018/04/19 21:47:31 by juochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
D_NAME = dbgr

LIB_DIR = ./libft/
LIB_FILE= libft.a
LIB = $(addprefix $(LIB_DIR), $(LIB_FILE))
LIB_LINK = -L$(LIB_DIR) -lft

HEADER = -I /includes

C_FLAG = -Wall -Werror -Wextra

SRC_DIR = srcs
SRC = 	main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

SRC_OBJ = $(SRC:.c=.o)

OBJ_DIR = objects

.PHONY: all clean fclean re qre

all: $(NAME)

$(NAME): $(LIB)
	@gcc -c $(SRCS) $(HEADER) $(C_FLAG)
	@gcc $(SRC_OBJ) $(LIB_LINK) -ltermcap -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[32mFile \"$(NAME)\" Created\033[0m"

$(D_NAME): $(LIB)
	@gcc -g $(SRCS) $(HEADER) $(LIB_LINK) -o $(D_NAME);
	@echo "\033[32mFile \"$(D_NAME)\" Created\033[0m"

$(LIB):
	@make -C $(LIB_DIR) all

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@make -C $(LIB_DIR) clean
	@echo "\033[31mObject File Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.a
	@rm -rf $(D_NAME) *.dSYM
	@make -C $(LIB_DIR) fclean
	@echo "\033[31mFile \"$(NAME)\" Removed\033[0m"

re: fclean all

qre:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@rm -rf $(NAME)
	@rm -rf *.a
	@rm -rf $(D_NAME) $(D_NAME).dSYM
	@gcc -c $(SRCS) $(HEADER) $(C_FLAG)
	@gcc $(SRC_OBJ) $(LIB_LINK) -ltermcap -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[32mQUICK RE\033[0m"
