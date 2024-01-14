/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_utilis_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:13:25 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/13 21:11:15 by cviegas          ###   ########.fr       */
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

void	print_both(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d ", a->nb);
			a = a->next;
		}
		else
			ft_printf("  ");
		if (b)
		{
			ft_printf("%d", b->nb);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\na b\n");
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
