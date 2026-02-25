# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 15:17:48 by mahendri          #+#    #+#              #
#    Updated: 2026/02/25 05:34:49 by mahendri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

HEADER = push_swap.h

SRC = \
	handle_split_utils.c \
	handle_split.c \
	handle_strings.c \
	handle_disorder.c \
	handle_flag.c \
	handle_bench.c \
	handle_stack.c \
	handle_stack_index.c \
	handle_stack_move.c \
	handle_stack_action.c \
	handle_stack_utils.c \
	handle_strategy.c \
	handle_validation.c \
	push_swap.c \
	push_swap_utils.c \
	solver_utils.c \
	solver_main.c \
	solver_minim.c \
	solver_simple.c \
	solver_medium.c \
	solver_complex.c \
	main_helper.c

SRC_BONUS = \
	get_next_line_utils.c \
	get_next_line.c \
	handle_split_utils.c \
	handle_split.c \
	handle_disorder.c \
	handle_flag.c \
	handle_stack.c \
	handle_stack_action.c \
	handle_stack_utils.c \
	handle_validation.c \
	push_swap_utils.c \
	execute_instruction_0.c \
	execute_instruction_1.c \
	execute_instruction_2.c \
	execute_instruction_move.c \
	checker_bonus.c \
	main_helper.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

bonus : $(FT_PRINTF) $(HEADER) $(OBJ_BONUS)
	${CC} ${FLAGS} ${OBJ_BONUS} ${FT_PRINTF} -o ${NAME_BONUS}

$(NAME) : $(FT_PRINTF) $(HEADER) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF) :
	@make -C $(FT_PRINTF_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	@make fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
