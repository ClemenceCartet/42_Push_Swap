/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:43:41 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/13 10:42:11 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	t_list	*stack;
	int		size;
}				t_stack;

typedef struct s_mv
{
	int	idx;
	int	moves;
}				t_mv;

typedef struct s_marks
{
	int		min_top_pck;
	int		max_top_pck;
	int		min_btm_pck;
	int		max_btm_pck;
}				t_marks;

//// push_swap.c
void	error(void);
void	feel_free(t_stack *a, t_stack *b);
void	init_struct(int argc, int *tab, t_stack *new);
void	print_stack(t_list *stack);
//// parsing.c
int		*init_rank(int argc, int *tab, int i);
t_list	*create_stack(int argc, int *tab);
int		check_is_number(char *str);
int		check_duplicat(int *tab, int nb);
int		*check_argv(int argc, char **argv);
//// sort_small.c
void	sort_three(t_list **a);
void	push_min(t_stack *a, t_stack *b, int nb);
void	sort_ten(t_stack *a, t_stack *b);
void	algo_small_list(t_stack *a, t_stack *b);
//// sort_big.c
void	push_to_b(t_stack *a, t_stack *b, int *i, t_marks mks);
void	push_to_a(t_stack *a, t_stack *b, int len);
void	algo_500(t_stack *a, t_stack *b, int middle, int len);
void	algo_big_list(t_stack *a, t_stack *b, int len);
//// push_swap_utils.c
int		ft_sqrt(int nb);
int		find_index(t_list *stack, int to_find);
t_mv	find_moves(t_stack *stk, int nb);
void	approximity_trick(t_stack *b, t_mv nb);
int		check_order(t_list *stack);
//// sa_sb_ss.c
void	swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
//// pa_pb.c
void	push(t_stack *one, t_stack *two);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
//// ra_rb_rr.c
void	rotate(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
//// rra_rrb_rrr.c
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **a, t_list **b);

#endif