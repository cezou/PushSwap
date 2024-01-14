/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:42:59 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 01:07:33 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	swap(t_stack *st)
{
	int	temp;

	if (st_size(st) <= 1)
		return ;
	temp = st->nb;
	st->nb = st->next->nb;
	st->next->nb = temp;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a)
		return ;
	st_add_front(b, st_new((*a)->nb, 0));
	temp = *a;
	(*a) = (*a)->next;
	free(temp);
}

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

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
