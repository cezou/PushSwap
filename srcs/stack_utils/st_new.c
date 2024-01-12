/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:22:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 19:00:49 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*st_new(int nb)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->nb = nb;
	st->next = NULL;
	return (st);
}
