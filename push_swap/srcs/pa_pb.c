/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:05:56 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/31 12:36:15 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *one, t_stack *two)
{
	t_list	*tmp;

	if (!two->stack)
	{
		tmp = one->stack;
		one->stack = one->stack->next;
		tmp->next = NULL;
		two->stack = tmp;
	}
	else
	{
		tmp = one->stack;
		one->stack = one->stack->next;
		tmp->next = two->stack;
		two->stack = tmp;
	}
	one->size--;
	two->size++;
}

void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
