/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:04:55 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/26 09:09:34 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/error/ft_printf_error.h"
# include <stdlib.h>

int		compare(void *s1, void *s2);
int		compare_numbers(void *s1, void *s2);
int		is_num(char *str);

t_list	*stack_at(t_list *lst, int index);
t_list	*gen_stack(int size, char **numbers);

int		lst_get_min_index(t_list *lst);
int		lst_get_max_index(t_list *lst);
t_list	*gen_stack_index(t_list **stack);

void	do_nothing_on_void(void *content);
void	del_node_content(void *content);
t_list	*list_pop_first(t_list **lst);
t_list	*list_pop_last(t_list **lst);

int		head_content_swap(t_list **lst, char *move, t_list **move_list);
int		stack_first_to_last(t_list **lst, char *move, t_list **move_list);
int		stack_last_to_first(t_list **lst, char *move, t_list **move_list);
int		stack_head_node_push(t_list **dest, t_list **src, char *move,
			t_list **move_list);

char	*print_strategy(int strategy, int disorder);

int		correct_strategy(char *arg);
int		adapt_strategy(int disorder);
int		set_strategy(int argc, char **argv);

int		find_sqrt(int num);
int		find_sequence(int num);
int		is_index_in_half(int index, t_list *stack);

int		is_splitable_arg(char *arg);
int		check_splitable(int argc, char **argv);
char	**split_all_arg(int argc, char **argv);
size_t	split_len(char **split);

int		skip_flag_on_check(char *arg, int *has_number);
char	**free_split(char **split, size_t size);
char	*strjoin_with_space(char const *s1, char const *s2);

t_list	*solver_minim(t_list **stack_a);
t_list	*solver_simple(t_list **stack_a);
t_list	*solver_medium(t_list **stack_a);
t_list	*solver_complex(t_list **stack_a);
int		solver_main(int argc, char **argv, int has_flag_bench, int strategy);

int		is_valid_flag(char *str);
int		is_flag(char *str);
int		check_for_flag(int argc, char **argv, char *flag);
int		count_flag(int argc, char **argv);
int		skip_flag(int argc, char **argv);

void	print_disorder(int disorder);
int		compute_disorder(t_list *stack);

int		compute_disorder(t_list *stack);
int		show_bench(t_list *move_list, int disorder, int strategy);

int		is_splitable_arg(char *arg);
int		is_all_numbers(int argc, char **argv);
int		check_double(int argc, char **argv);
int		valid_args(int argc, char **argv);

int		move_register(t_list **move_list, char *move);
void	print_move_list(t_list *lst);

#endif
