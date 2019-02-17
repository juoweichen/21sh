# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2019/02/13 18:57:18 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh		# project bin file
D_NAME = dbgr	# debugger bin file

# libft section
LIB_DIR = ./libft/
LIB_FILE= libft.a
LIB = $(addprefix $(LIB_DIR), $(LIB_FILE))
LIB_LINK = -L$(LIB_DIR) -lft

# compile flag
OUTER_LINK = -ltermcap
HEADER = -I /includes
W_FLAG = -Wall -Werror -Wextra

# src section
SRC_DIR = srcs
SRC = 	main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

# obj seciton
SRC_OBJ = $(SRC:.c=.o)
OBJ_DIR = objects

.PHONY: all clean fclean re qre

all: $(NAME)

# compile project bin
$(NAME): $(LIB)
	@gcc -c $(SRCS) $(HEADER) $(W_FLAG)
	@gcc $(SRC_OBJ) $(LIB_LINK) $(OUTER_LINK) -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[32mFile \"$(NAME)\" Created\033[0m"
# compile debugger bin
$(D_NAME): $(LIB)
	@gcc -g $(SRCS) $(HEADER) $(LIB_LINK) -o $(D_NAME);
	@echo "\033[32mFile \"$(D_NAME)\" Created\033[0m"
# compile libft
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
# quick-re, won't re-compile libft or other lib
qre:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@rm -rf $(NAME)
	@rm -rf *.a
	@rm -rf $(D_NAME) $(D_NAME).dSYM
	@gcc -c $(SRCS) $(HEADER) $(W_FLAG)
	@gcc $(SRC_OBJ) $(LIB_LINK) $(OUTER_LINK) -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "\033[32mQUICK RE\033[0m"
