# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 22:57:41 by dmarsell          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/08/08 21:47:22 by dmarsell         ###   ########.fr        #
=======
#    Updated: 2020/08/08 23:13:46 by cassunta         ###   ########.fr        #
>>>>>>> origin/Anna
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc -Wall -Wextra -g

HD = ft_ls.h

OBJ_DIR = obj_ls

LIBFT_DIR = libft

LIBFT = libft.a

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC = file_info.c \
		slash_strjoin.c \
		sort.c          \
		take_in_list.c	\
		time_sort.c		\
		parsing.c		\
		start_file.c	\
		additional.c    \
		parse_big.c     \
		parse_big2.c	\
		display.c		\
        format_date.c	\
		format.c
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)
	@echo "\033[32m [OK] \033[0m\033[32mCompiling execution file:\033[36m " $(NAME)

$(OBJ): $(OBJ_DIR)/%.o: ./%.c $(HD)
	@$(CC) -I $(HD) -o $@ -c $<
	@echo "\033[32m [OK] \033[0m\033[32mCompiling:\033[36m " $@

$(OBJ_DIR): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
		@mkdir $(OBJ_DIR)
		@echo "\033[32m [OK] \033[0m\033[32mMaking catalog:\033[36m " $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting catalog and binaries:\033[33m " $(OBJ_DIR)
		@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting execution file:\033[33m " $(NAME)
		@make filecl -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
