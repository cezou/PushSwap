/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:53:26 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 15:36:39 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_stacks_a(t_tuple *t)
{
	set_pos_and_median(t->a);
	set_pos_and_median(t->b);
	set_target_a(t);
	set_push_costs_a(t);
	set_cheapest_a(t);
}

void	set_pos_and_median(t_stack *st)
{
	size_t	i;
	size_t	median;

	median = st_size(st) / 2;
	i = 0;
	while (st)
	{
		if (i <= median)
			st->is_above_median = 1;
		else
			st->is_above_median = 0;
		st->pos = i;
		st = st->next;
		i++;
	}
}

// The target is the closest smaller number in stack b. If there is no smaller
// number, then the target becomes the biggest number of the stack b.
void	set_target_a(t_tuple *t)
{
	t_stack	*target;
	t_stack	*a;
	t_stack	*b;
	long	best_for_now;

	a = t->a;
	while (a)
	{
		best_for_now = (long)MIN_INT - 1;
		b = t->b;
		while (b)
		{
			if (b->nb < a->nb && b->nb > best_for_now)
			{
				best_for_now = b->nb;
				target = b;
			}
			b = b->next;
		}
		if (best_for_now == (long)MIN_INT - 1)
			a->target = st_max(t->b);
		else
			a->target = target;
		a = a->next;
	}
}

// The push cost of each stack is its cost to be on top
// + the cost for its target to be on top
void	set_push_costs_a(t_tuple *t)
{
	t_stack	*a;

	a = t->a;
	while (a)
	{
		if (a->is_above_median && a->target->is_above_median)
			a->push_cost = ft_bmax(a->pos, a->target->pos);
		else if (!a->is_above_median && !a->target->is_above_median)
			a->push_cost = ft_bmax(st_size(t->a) - a->pos, st_size(t->b)
					- a->target->pos);
		else if (a->target->is_above_median)
			a->push_cost = a->target->pos + st_size(t->a) - a->pos;
		else
			a->push_cost = st_size(t->b) - a->target->pos + a->pos;
		a = a->next;
	}
}

// We find the cheapest (the min(cost))
// Then we sets all is_cheapest booleans if it's him or not
void	set_cheapest_a(t_tuple *t)
{
	t_stack	*a;
	t_stack	*cheapest;

	cheapest = t->a;
	a = cheapest->next;
	while (a)
	{
		if (a->push_cost < cheapest->push_cost)
			cheapest = a;
		a = a->next;
	}
	a = t->a;
	while (a)
	{
		if (a->pos == cheapest->pos)
			a->is_cheapest = 1;
		else
			a->is_cheapest = 0;
		a = a->next;
	}
}
