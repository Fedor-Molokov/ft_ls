# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 20:34:57 by dmarsell          #+#    #+#              #
#    Updated: 2020/07/27 14:06:35 by dmarsell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft

LIBFT = stlibft.a

CC = gcc

CFLAGS = -Wall -Wextra -g

INCL = ft_printf.h

TEST = ft_printf

OBJ_DIR = obj_printf

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC = begin.c \
				ft_printf.c \
				print_addres.c \
				count_decimal.c \
				count_decimal_next.c \
				count_decimal_next_n.c \
				print_decimal.c \
				print_decimal_next.c \
				additional.c \
				additional_next.c \
				o_x.c \
				o_x_l.c \
				printing_nums.c \
				printing_nums_next.c \
				char.c \
				char_next.c \
				calc_float.c \
				calc_float_next.c \
				print_float.c \
				make_flags_2.c \
				make_flags.c 

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@cp ../$(LIBFT) $(NAME)
	@echo "\033[32m [OK] \033[0m\033[32mCoping:\033[36m "$(LIBFT) "\033[0m\033[32mwith:\033[36m "$(NAME)
		@ar rc $(NAME) $(OBJ)
		@echo "\033[32m [OK] \033[0m\033[32mArchive binaries and:\033[36m " $(NAME)
			@ranlib $(NAME)
			@echo "\033[32m [OK] \033[0m\033[32mRunlib library:\033[36m " $(NAME)

$(OBJ): $(OBJ_DIR)/%.o: ./%.c $(INCL)
	@$(CC) $(CFLAGS) -I $(INCL) -o $@ -c $<
	@echo "\033[32m [OK] \033[0m\033[32mCompiling:\033[36m " $@

$(OBJ_DIR): 
	@mkdir -p $(OBJ_DIR)
	@echo "\033[32m [OK] \033[0m\033[32mMaking catalog:\033[36m " $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(DC) $(GC) $(SYM)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting catalog and binaries:\033[33m " $(OBJ_DIR)

fclean: 
	@rm -f $(NAME)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting library binary:\033[33m " $(NAME)

re: clean all

.PHONY: all clean fclean re
