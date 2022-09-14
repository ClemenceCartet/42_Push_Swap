/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:07:27 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/13 10:39:27 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	feel_free(t_stack *a, t_stack *b)
{
	ft_lstclear(&(a->stack), del);
	ft_lstclear(&(b->stack), del);
}

void	init_struct(int argc, int *tab, t_stack *new)
{
	if (tab == NULL)
		new->stack = NULL;
	else
		new->stack = create_stack(argc, tab);
	new->size = argc - 1;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*tab;

	if (argc < 2)
		return (0);
	tab = check_argv(argc, argv);
	if (check_duplicat(tab, argc - 1) == 1)
		error();
	init_struct(1, NULL, &b);
	init_struct(argc, tab, &a);
	if (check_order(a.stack) == 0)
		exit(0);
	if (a.size <= 11)
		algo_small_list(&a, &b);
	else
		algo_big_list(&a, &b, a.size);
	feel_free(&a, &b);
	return (EXIT_SUCCESS);
}
