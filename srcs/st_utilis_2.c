/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_utilis_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:13:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/17 16:11:46 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	st_print(t_stack *st)
{
	while (st)
	{
		ft_printf("%d", st->nb);
		if (st->next)
			ft_printf(" ");
		else
			ft_printf("\n");
		st = st->next;
	}
}

void	t_print(t_tuple t)
{
	ft_printf("\n   a | b  \n-----|-----\n");
	while (t.a || t.b)
	{
		if (t.a)
		{
			ft_printf("%d: %d | ", t.a->pos, t.a->nb);
			t.a = t.a->next;
		}
		else
			ft_printf("  ");
		if (t.b)
		{
			ft_printf("%d", t.b->nb);
			t.b = t.b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

size_t	st_size(t_stack *st)
{
	size_t	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

t_stack	*st_max(t_stack *st)
{
	t_stack	*max;

	max = st;
	st = st->next;
	while (st)
	{
		if (st->nb > max->nb)
			max = st;
		st = st->next;
	}
	return (max);
}
