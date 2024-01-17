/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:53:26 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/17 16:37:00 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_pos_and_median(t_stack *st)
{
	size_t	i;
	size_t	median;

	median = st_size(st) / 2;
	i = 0;
	while (st)
	{
		if (i <= median)
			st->above_median = 1;
		else
			st->above_median = 0;
		st->pos = i;
		st = st->next;
		i++;
	}
}

// The target is the closest smaller number in stack b. If there is no smaller number,
// then the target becomes the bigger number of the stack b.
void	set_target_a(t_tuple *t)
{
	t_stack	*target;
	t_stack	*a;
	t_stack	*b;
	long	best_for_now;

	best_for_now = MIN_INT - 1;
	a = t->a;
	while (a)
	{
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
		if (best_for_now == MIN_INT - 1)
			a->target = st_max(t->b);
		else
			a->target = target;
		a = a->next;
	}
}

void	init_stacks(t_tuple *t)
{
	set_pos_and_median(t->a);
	set_pos_and_median(t->b);
	set_target_a(t);
	// Analyze cost;
	// find cheapest;
}
