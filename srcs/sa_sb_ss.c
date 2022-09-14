/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:26 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/31 12:36:41 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*third;

	first = *stack;
	third = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = first;
	first->next = third;
}

void	sa(t_list **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
