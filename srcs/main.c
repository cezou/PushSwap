/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/15 21:19:13 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_tuple *t)
{
	if (t->a->nb > t->a->next->nb)
		ra(t);
}
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

void	sort_algo(t_tuple *t)
{
	if (st_size(t->a) <= 1)
		return ;
	if (st_size(t->a) == 2)
		return (sort_2(t));
	if (st_size(t->a) == 3)
		return (sort_3(t));
}

int	main(int ac, char **av)
{
	t_tuple	t;

	if (ac <= 1)
		return (0);
	if (!init_and_hold_errors(&t.a, &t.b, ac, av))
		return (0);
	t_print(t);
	sort_algo(&t);
	t_print(t);
	t_clear(&t);
}
