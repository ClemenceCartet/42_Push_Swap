/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:53:44 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/13 10:37:36 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 1)
		return (0);
	while (i <= 46340)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

int	find_index(t_list *stack, int to_find)
{
	int	*nb;
	int	i;

	i = 1;
	while (stack && stack->next != NULL)
	{
		nb = stack->content;
		if (*nb == to_find)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

t_mv	find_moves(t_stack *stk, int nb)
{
	t_mv	mv;
	int		middle;

	middle = stk->size / 2 + 1;
	mv.idx = find_index(stk->stack, nb);
	if (mv.idx <= middle)
		mv.moves = mv.idx - 1;
	else
		mv.moves = (stk->size - mv.idx) + 1;
	return (mv);
}

void	approximity_trick(t_stack *b, t_mv nb)
{
	int	middle;

	middle = b->size / 2 + 1;
	if (nb.idx == 2)
		sb(&b->stack);
	else if (nb.idx <= middle)
		while (nb.moves-- != 0)
			rb(&b->stack);
	else
		while (nb.moves-- != 0)
			rrb(&b->stack);
}

int	check_order(t_list *stack)
{
	int		*n1;
	int		*n2;
	int		i;

	i = 0;
	while (stack && stack->next != NULL)
	{
		n1 = stack->content;
		n2 = stack->next->content;
		if (*n1 > *n2)
			i++;
		stack = stack->next;
	}
	return (i);
}
