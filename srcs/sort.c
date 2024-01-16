/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:11:36 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/16 19:23:25 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// When there is only two numbers in stack a
void	sort_2(t_tuple *t)
{
	if (t->a->nb > t->a->next->nb)
		ra(t);
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
	if (first->nb < second->nb && second->nb < third->nb)
		return ;
	if (first->nb > second->nb && second->nb > third->nb)
		return (sa(*t), rra(t));
	if (first->nb < second->nb && second->nb > third->nb)
	{
		if (first->nb < third->nb)
			return (rra(t), sa(*t));
		return (rra(t));
	}
	if (first->nb > second->nb && second->nb < third->nb
		&& first->nb > third->nb)
		return (ra(t));
	return (sa(*t));
}

void	turkish_algo(t_tuple *t)
{
	pa(t);
	if (st_size(t->a) > 3)
		pa(t);
	while (st_size(t->a) > 3)
	{
		// Push to B
		// Sort in descending order B
	}
	sort_3(t);
	while (st_size(t->b) > 0)
	{
		// Push to A
		// Sort it in ascending order.
	}
	// Sort MIN
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