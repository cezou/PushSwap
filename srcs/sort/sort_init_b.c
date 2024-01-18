/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:47:39 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 17:44:23 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_stacks_b(t_tuple *t)
{
	set_pos_and_median(t->a);
	set_pos_and_median(t->b);
	set_target_b(t);
}

// The target is the closest bigger number in stack b. If there is no smaller
// number, then the target becomes the smallest number of the stack b.
void	set_target_b(t_tuple *t)
{
	t_stack	*target;
	t_stack	*a;
	t_stack	*b;
	long	best_for_now;

	b = t->b;
	while (b)
	{
		best_for_now = (long)MAX_INT + 1;
		a = t->a;
		while (a)
		{
			if (a->nb > b->nb && a->nb < best_for_now)
			{
				best_for_now = a->nb;
				target = a;
			}
			a = a->next;
		}
		if (best_for_now == (long)MAX_INT + 1)
			b->target = st_min(t->a);
		else
			b->target = target;
		b = b->next;
	}
}
