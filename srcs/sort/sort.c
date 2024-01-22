/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:11:36 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 16:43:30 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_algo(t_tuple *t)
{
	if (st_size(t->a) <= 1 || is_sorted(t->a))
		return ;
	if (st_size(t->a) == 2)
		return (sort_2(t));
	if (st_size(t->a) == 3)
		return (sort_3(t));
	turkish_algo(t);
}

void	turkish_algo(t_tuple *t)
{
	pb(t, 1);
	if (st_size(t->a) > 3)
		pb(t, 1);
	while (st_size(t->a) > 3)
	{
		init_stacks_a(t);
		move_cheapest_to_b(t);
	}
	sort_3(t);
	while (t->b)
	{
		init_stacks_b(t);
		move_to_a(t);
	}
	set_pos_and_median(t->a);
	if (st_min(t->a)->is_above_median)
		while (t->a != st_min(t->a))
			ra(t, 1);
	else
		while (t->a != st_min(t->a))
			rra(t, 1);
}

bool	is_sorted(t_stack *st)
{
	int	temp;

	temp = st->nb;
	st = st->next;
	while (st)
	{
		if (st->nb < temp)
			return (0);
		temp = st->nb;
		st = st->next;
	}
	return (1);
}

// When there is only two numbers in stack a
void	sort_2(t_tuple *t)
{
	if (t->a->nb > t->a->next->nb)
		ra(t, 1);
}

// When there is only three numbers in stack a
void	sort_3(t_tuple *t)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = t->a;
	second = first->next;
	third = second->next;
	if (is_sorted(t->a))
		return ;
	if (first->nb > second->nb && second->nb > third->nb)
		return (sa(*t, 1), rra(t, 1));
	if (first->nb < second->nb && second->nb > third->nb)
	{
		if (first->nb < third->nb)
			return (rra(t, 1), sa(*t, 1));
		return (rra(t, 1));
	}
	if (first->nb > second->nb && second->nb < third->nb
		&& first->nb > third->nb)
		return (ra(t, 1));
	return (sa(*t, 1));
}
