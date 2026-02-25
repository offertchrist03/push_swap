# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 20:18:14 by mahendri          #+#    #+#              #
#    Updated: 2026/02/18 05:29:46 by mahendri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -Ilibft -Isrc -Iutils

SRC_CORE = \
	src/ft_printf.c \
	src/handle_format.c \
	src/ft_printchar.c \
	src/ft_printstr.c \
	src/ft_printnbr.c \
	src/ft_printnbr_unsigned.c \
	src/ft_printhex.c \
	src/ft_printptr.c

SRC_ERROR = \
	error/ft_printf_error.c \
	error/handle_format_error.c

SRC_UTILS = \
	utils/utils.c \
	utils/ft_itoh.c \
	utils/ft_itoa_unsigned.c

SRC = \
	$(SRC_CORE) \
	$(SRC_ERROR) \
	$(SRC_UTILS)

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
