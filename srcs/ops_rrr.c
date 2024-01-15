/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:38:04 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/15 20:05:41 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// rrr : rra and rrb at the same time.
void	rrr(t_tuple *t)
{
	rrotate(&t->a);
	rrotate(&t->b);
	ft_printf("rrr\n");
}
