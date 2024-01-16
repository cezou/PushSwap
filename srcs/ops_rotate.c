/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:09:10 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/16 15:01:40 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
void	ra(t_tuple *t)
{
	rotate(&t->a);
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
void	rb(t_tuple *t)
{
	rotate(&t->b);
	ft_printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_tuple *t)
{
	rotate(&t->a);
	rotate(&t->b);
	ft_printf("rr\n");
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	rra(t_tuple *t)
{
	rrotate(&t->a);
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	rrb(t_tuple *t)
{
	rrotate(&t->b);
	ft_printf("rrb\n");
}
