/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:02:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 18:32:14 by cviegas          ###   ########.fr       */
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

void	move_cheapest_to_b(t_tuple *t)
{
	t_stack	*cheapest;
	int		cheapest_nb;
	int		target_nb;

	cheapest = find_cheapest(t->a);
	target_nb = cheapest->target->nb;
	cheapest_nb = cheapest->nb;
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		while (t->a->nb != cheapest_nb && t->b->nb != target_nb)
			rr(t);
	if (!(cheapest->is_above_median) && !(cheapest->target->is_above_median))
		while (t->a->nb != cheapest_nb && t->b->nb != target_nb)
			rrr(t);
	if (cheapest->is_above_median)
		while (t->a->nb != cheapest_nb)
			ra(t);
	else
		while (t->a->nb != cheapest_nb)
			rra(t);
	if (cheapest->target->is_above_median)
		while (t->b->nb != target_nb)
			rb(t);
	else
		while (t->b->nb != target_nb)
			rrb(t);
	pb(t);
}

void	move_to_a(t_tuple *t)
{
	int	target_nb;

	target_nb = t->b->target->nb;
	if (t->b->target->is_above_median)
		while (t->a->nb != target_nb)
			ra(t);
	else
		while (t->a->nb != target_nb)
			rra(t);
	pa(t);
}
