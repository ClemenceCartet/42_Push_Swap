/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:14:21 by ccartet           #+#    #+#             */
/*   Updated: 2022/02/13 10:42:04 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicat(int *tab, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb - 1)
	{
		j = i + 1;
		while (j < nb)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*check_argv(int argc, char **argv)
{
	int	nb;
	int	*tab;
	int	i;

	nb = 1;
	i = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		exit(EXIT_FAILURE);
	while (nb < argc)
	{
		if (argv[nb][0] == '\0')
			error();
		if (!check_is_number(argv[nb]))
			error();
		if (ft_atol(argv[nb]) > INT_MAX || ft_atol(argv[nb]) < INT_MIN)
			error();
		if (argc == 2)
			exit(0);
		tab[i] = ft_atoi(argv[nb]);
		nb++;
		i++;
	}
	return (tab);
}

int	*init_rank(int argc, int *tab, int i)
{
	int	*rank;
	int	a;

	rank = malloc(sizeof(int));
	if (!rank)
		exit(EXIT_FAILURE);
	a = 0;
	(*rank)++;
	while (a < argc - 1)
	{
		if (tab[i] > tab[a])
			(*rank)++;
		a++;
	}
	return (rank);
}

t_list	*create_stack(int argc, int *tab)
{
	t_list	*stack_a;
	t_list	*tmp;
	int		i;

	stack_a = NULL;
	tmp = NULL;
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_lstnew(init_rank(argc, tab, i));
		if (!tmp)
			exit(EXIT_FAILURE);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	free(tab);
	return (stack_a);
}
