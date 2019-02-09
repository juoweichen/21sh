# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2018/04/16 18:38:10 by juochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = -I /includes

W_FLAG = -Wall -Werror -Wextra

SRC_DIR = srcs
SRCS =	$(wildcard $(SRC_DIR)/dict/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_int/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_is/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_lst/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_mem/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_mstr/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_printf/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_put/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_str/*.c)
SRCS += $(wildcard $(SRC_DIR)/get_next_line/*.c)
SRCS += $(wildcard $(SRC_DIR)/ft_dlst/*.c)
SRCS_OBJ = $(SRCS:.c=.o)

OBJS = $(notdir $(SRCS_OBJ))
OBJ_DIR = objects

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(W_FLAG) $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@mkdir $(OBJ_DIR)
	@mv $(OBJS) $(OBJ_DIR)
	@echo "\033[33mlibft Binary File Created\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@echo "\033[31mlibft Object File Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.a
	@echo "\033[31mlibft Binary File Removed\033[0m"

re: fclean all
