# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2019/11/23 21:49:32 by mcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project bin file
NAME = 21sh

# debugger bin file
D_NAME = dbgr

# libft section
LIB_DIR = ./libft/
LIB_FILE= libft.a
LIB = $(addprefix $(LIB_DIR), $(LIB_FILE))
LIB_LINK = -L$(LIB_DIR) -lft
LIB_HEADER = -I srcs/libft/includes

# compile flag
OUTER_LINK = -ltermcap -fsanitize=address
HEADER = -I /includes
W_FLAG = -Wall -Werror -Wextra

# src section
SRC_DIR = srcs
SRCS = $(wildcard $(SRC_DIR)/globby/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/astree/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/exec/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/lexer/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/line/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/signals/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/string/*.c)
SRCS +=	$(wildcard $(SRC_DIR)/env/*.c)
SRCS += $(wildcard $(SRC_DIR)/print_tree/*.c)
SRCS += $(wildcard $(SRC_DIR)/trie/*.c)
SRCS += $(wildcard $(SRC_DIR)/radix_tree/*.c)
SRCS += $(wildcard $(SRC_DIR)/*.c)

.PHONY: all clean fclean re qre

all: $(NAME)

# compile project bin
$(NAME): $(LIB)
	@gcc $(SRCS) $(HEADER) $(LIB_HEADER) $(W_FLAG) $(LIB_LINK) $(OUTER_LINK) -o $(NAME)
	@echo "\033[32mFile \"$(NAME)\" Created\033[0m"
# compile debugger bin
$(D_NAME): $(LIB)
	@gcc -g $(SRCS) $(HEADER) $(LIB_HEADER) $(W_FLAG) $(LIB_LINK) $(OUTER_LINK) -o $(D_NAME);
	@echo "\033[32mFile \"$(D_NAME)\" Created\033[0m"
# compile libft
$(LIB):
	@make -C $(LIB_DIR) all

clean:
	@make -C $(LIB_DIR) clean
	@echo "\033[31mObject File Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(D_NAME) $(D_NAME).dSYM
	@make -C $(LIB_DIR) fclean
	@echo "\033[31mFile \"$(NAME)\" Removed\033[0m"

re: fclean all
# quick-re, won't re-compile libft or other lib
qre:
	@rm -rf $(NAME)
	@rm -rf *.a
	@rm -rf $(D_NAME) $(D_NAME).dSYM
	@gcc $(SRCS) $(HEADER) $(W_FLAG) $(LIB_LINK) $(OUTER_LINK) -o $(NAME)
	@echo "\033[32mQUICK RE\033[0m"

# valgrind --leak-check=yes --memcheck:leak-check=full --show-reachable=yes ./42sh
