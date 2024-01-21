/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:42:59 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 17:44:15 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
void	sa(t_tuple t, bool print_or_not)
{
	swap(t.a);
	if (print_or_not)
		ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_tuple t, bool print_or_not)
{
	swap(t.b);
	if (print_or_not)
		ft_printf("sb\n");
}

// ss : sa and sb at the same time.
void	ss(t_tuple t, bool print_or_not)
{
	swap(t.a);
	swap(t.b);
	if (print_or_not)
		ft_printf("ss\n");
}

// pa (push a):
// Take the first element at the top of b and put it at the top of a
void	pa(t_tuple *t, bool print_or_not)
{
	push(&t->b, &t->a);
	if (print_or_not)
		ft_printf("pa\n");
}

// pb (push b):
// Take the first element at the top of a and put it at the top of b.
void	pb(t_tuple *t, bool print_or_not)
{
	push(&t->a, &t->b);
	if (print_or_not)
		ft_printf("pb\n");
}
