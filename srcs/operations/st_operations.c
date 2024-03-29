/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:42:59 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 17:44:17 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swap the two first elements of a specific stack
void	swap(t_stack *st)
{
	int	temp;

	if (st_size(st) <= 1)
		return ;
	temp = st->nb;
	st->nb = st->next->nb;
	st->next->nb = temp;
}

// Push the first element of a stack to the top of another
void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	st_add_front(b, st_new((*a)->nb, 0));
	temp = *a;
	(*a) = (*a)->next;
	free(temp);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate(t_stack **st)
{
	t_stack	*temp;

	if (st_size(*st) <= 1)
		return ;
	st_add_back(st, st_new((*st)->nb, st_size(*st)));
	temp = (*st);
	(*st) = (*st)->next;
	free(temp);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rrotate(t_stack **st)
{
	t_stack	*b_last;
	t_stack	*last;

	if (st_size(*st) <= 1)
		return ;
	b_last = *st;
	while (b_last->next->next)
		b_last = b_last->next;
	last = b_last->next;
	st_add_front(st, st_new(last->nb, 0));
	b_last->next = NULL;
	free(last);
}
