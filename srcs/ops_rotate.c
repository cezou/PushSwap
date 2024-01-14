/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:09:10 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 20:42:44 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_tuple *t)
{
	rotate(&t->a);
	ft_printf("ra\n");
}

void	rb(t_tuple *t)
{
	rotate(&t->b);
	ft_printf("rb\n");
}

void	rr(t_tuple *t)
{
	rotate(&t->a);
	rotate(&t->b);
	ft_printf("rr\n");
}

void	rra(t_tuple *t)
{
	rrotate(&t->a);
	ft_printf("rra\n");
}

void	rrb(t_tuple *t)
{
	rrotate(&t->b);
	ft_printf("rrb\n");
}
