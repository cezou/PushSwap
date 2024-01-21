/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:02:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 18:51:56 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_cheapest(t_stack *st)
{
	while (st)
	{
		if (st->is_cheapest)
			return (st);
		st = st->next;
	}
	return (st);
}

t_cheapest	init_temp_cheapest(t_stack *st)
{
	t_stack		*cheapest;
	t_cheapest	new;

	cheapest = find_cheapest(st);
	new.target_nb = cheapest->target->nb;
	new.cheapest_nb = cheapest->nb;
	new.cheapest_is_above = cheapest->is_above_median;
	new.target_is_above = cheapest->target->is_above_median;
	return (new);
}

void	move_cheapest_to_b(t_tuple *t)
{
	t_cheapest	c;

	c = init_temp_cheapest(t->a);
	if (c.cheapest_is_above && c.target_is_above)
		while (t->a->nb != c.cheapest_nb && t->b->nb != c.target_nb)
			rr(t, 1);
	if (!c.cheapest_is_above && !c.target_is_above)
		while (t->a->nb != c.cheapest_nb && t->b->nb != c.target_nb)
			rrr(t, 1);
	if (c.cheapest_is_above)
		while (t->a->nb != c.cheapest_nb)
			ra(t, 1);
	else
		while (t->a->nb != c.cheapest_nb)
			rra(t, 1);
	if (c.target_is_above)
		while (t->b->nb != c.target_nb)
			rb(t, 1);
	else
		while (t->b->nb != c.target_nb)
			rrb(t, 1);
	pb(t, 1);
}

void	move_to_a(t_tuple *t)
{
	int	target_nb;

	target_nb = t->b->target->nb;
	if (t->b->target->is_above_median)
		while (t->a->nb != target_nb)
			ra(t, 1);
	else
		while (t->a->nb != target_nb)
			rra(t, 1);
	pa(t, 1);
}
