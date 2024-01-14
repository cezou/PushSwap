/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:42:59 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 20:41:18 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_tuple t)
{
	swap(t.a);
	ft_printf("sa\n");
}

void	sb(t_tuple t)
{
	swap(t.b);
	ft_printf("sb\n");
}

void	ss(t_tuple t)
{
	swap(t.a);
	swap(t.b);
	ft_printf("ss\n");
}

void	pa(t_tuple *t)
{
	push(&t->b, &t->a);
	ft_printf("pa\n");
}

void	pb(t_tuple *t)
{
	push(&t->a, &t->b);
	ft_printf("pb\n");
}
