/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:19:16 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/11 13:59:44 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **a)
{
	int	*n1;
	int	*n2;
	int	*n3;

	n1 = (*a)->content;
	n2 = (*a)->next->content;
	n3 = (*a)->next->next->content;
	if (*n1 > *n2 && *n1 < *n3)
		sa(a);
	else if (*n1 > *n2 && *n2 > *n3)
	{
		sa(a);
		rra(a);
	}
	else if (*n1 < *n2 && *n1 < *n3)
	{
		sa(a);
		ra(a);
	}
	else if (*n1 < *n2 && *n1 > *n3)
		rra(a);
	else
		ra(a);
}

void	push_min(t_stack *a, t_stack *b, int nb)
{
	int		median;
	t_mv	min;

	min.idx = find_index(a->stack, nb);
	median = a->size / 2 + 1;
	if (min.idx <= median)
	{
		min.moves = min.idx - 1;
		while (min.moves-- != 0)
			ra(&a->stack);
	}
	else
	{
		min.moves = (a->size - min.idx) + 1;
		while (min.moves-- != 0)
			rra(&a->stack);
	}
	pb(a, b);
}

void	sort_ten(t_stack *a, t_stack *b)
{
	int	min;
	int	len;

	min = 1;
	len = a->size;
	while (a->size > 3)
	{
		push_min(a, b, min);
		min++;
	}
	if (check_order(a->stack) != 0)
		sort_three(&a->stack);
	while (a->size < len)
		pa(b, a);
}

void	algo_small_list(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(&a->stack);
	else if (a->size == 3)
		sort_three(&a->stack);
	else
		sort_ten(a, b);
}
