# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 20:42:18 by dmarsell          #+#    #+#              #
#    Updated: 2020/07/27 14:06:20 by dmarsell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = stlibft.a

NAMEFIN = libft.a

PRINTF = libftprintf.a

OBJ_DIR = obj_libft

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

PRINTF_DIR = ft_printf

CC = gcc

CFLAGS = -Wall -Wextra -g

HD = libft.h

SRC = ft_atoi.c	ft_memccpy.c	ft_putendl.c	ft_strcmp.c	ft_strlen.c	ft_strrchr.c\
ft_bzero.c	ft_memchr.c	ft_putendl_fd.c	ft_strcpy.c	ft_strmap.c	ft_strsplit.c\
ft_isalnum.c	ft_memcmp.c	ft_putnbr.c	ft_strdel.c	ft_strmapi.c	ft_strstr.c\
ft_isalpha.c	ft_memcpy.c	ft_putnbr_fd.c	ft_strdup.c	ft_strncat.c	ft_strsub.c\
ft_isascii.c	ft_memdel.c	ft_putstr.c	ft_strequ.c	ft_strncmp.c	ft_strtrim.c\
ft_isdigit.c	ft_memmove.c	ft_putstr_fd.c	ft_striter.c	ft_strncpy.c	ft_tolower.c\
ft_isprint.c	ft_memset.c	ft_strcat.c	ft_striteri.c	ft_strnequ.c	ft_toupper.c\
ft_itoa.c	ft_putchar.c	ft_strchr.c	ft_strnew.c ft_strjoin.c \
ft_memalloc.c	ft_putchar_fd.c	ft_strclr.c	ft_strlcat.c	ft_strnstr.c

all: $(NAME)
	
$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m [OK] \033[0m\033[32mArchive binaries and:\033[36m " $(NAME)
		@ranlib $(NAME)
		@echo "\033[32m [OK] \033[0m\033[32mRunlib library:\033[36m " $(NAME)
			@make -C $(PRINTF_DIR)
			@mv $(PRINTF_DIR)/$(PRINTF) ./
				@mv $(PRINTF) $(NAMEFIN)
				@echo "\033[32m [OK] \033[0m\033[32mRename library:\033[36m " $(NAMEFIN) 

$(OBJ): $(OBJ_DIR)/%.o: ./%.c $(HD)
	@$(CC) $(CFLAGS) -I $(HD) -o $@ -c $<
	@echo "\033[32m [OK] \033[0m\033[32mCompiling:\033[36m " $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\033[32m [OK] \033[0m\033[32mMaking catalog:\033[36m " $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ_DIR) $(OBJ)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting catalog and binaries:\033[33m " $(OBJ_DIR)
		@make clean -C $(PRINTF_DIR)
		
fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting library binary:\033[33m " $(NAME)
		@rm -f $(NAMEFIN)
		@echo "\033[31m [OK] \033[0m\033[31mDeleting library binary:\033[33m " $(NAMEFIN)
		
filecl:
	@rm -f $(NAME)
	@echo "\033[31m [OK] \033[0m\033[31mDeleting library binary:\033[33m " $(NAME)
		@rm -f $(NAMEFIN)
		@echo "\033[31m [OK] \033[0m\033[31mDeleting library binary:\033[33m " $(NAMEFIN)
			@make fclean -C $(PRINTF_DIR)
	
re: fclean all

.PHONY: all clean fclean filecl re