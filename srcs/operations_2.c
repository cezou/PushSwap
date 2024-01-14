/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:09:10 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 01:24:34 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
}
void	rrotate(t_stack **st)
{
	t_stack	*b_last;
	t_stack	*last;

	b_last = *st;
	while (b_last->next->next)
		b_last = b_last->next;
	last = b_last->next;
	st_add_front(st, st_new(last->nb, 0));
	b_last->next = NULL;
	free(last);
}
