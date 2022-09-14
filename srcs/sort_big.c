/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:20 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/13 10:37:00 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int *i, t_marks mks)
{
	int	*nb;
	int	*snb;

	nb = a->stack->content;
	snb = a->stack->next->content;
	if (*nb > mks.min_top_pck && *nb <= mks.max_top_pck)
	{
		pb(a, b);
		if ((*i) != 0)
		{
			if (*snb <= mks.min_top_pck || *snb > mks.max_btm_pck)
				rr(&a->stack, &b->stack);
			else
				rb(&b->stack);
		}
		(*i)++;
	}
	else if (*nb > mks.min_btm_pck && *nb <= mks.max_btm_pck)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(&a->stack);
}

void	push_to_a(t_stack *a, t_stack *b, int len)
{
	int		max;
	t_mv	mx;

	max = len;
	while (a->size != len)
	{
		mx = find_moves(b, max);
		approximity_trick(b, mx);
		pa(b, a);
		max--;
	}
}

void	algo_500(t_stack *a, t_stack *b, int middle, int len)
{
	t_marks	mks;
	int		size_packs;
	int		sqrt_len;
	int		i;
	int		j;

	sqrt_len = ft_sqrt(len);
	size_packs = len / sqrt_len;
	mks.max_top_pck = middle;
	mks.min_top_pck = middle - size_packs;
	mks.min_btm_pck = middle;
	mks.max_btm_pck = middle + size_packs;
	j = 0;
	while (j < sqrt_len / 2 || mks.min_top_pck > 0)
	{
		i = 0;
		while (i < (size_packs * 2) - 1)
			push_to_b(a, b, &i, mks);
		j++;
		mks.min_top_pck -= size_packs;
		mks.max_btm_pck += size_packs;
	}
	while (a->size != 0)
		pb(a, b);
}

void	algo_big_list(t_stack *a, t_stack *b, int len)
{
	int	middle;

	middle = len / 2;
	algo_500(a, b, middle, len);
	push_to_a(a, b, len);
}
