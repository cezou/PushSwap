/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 06:52:27 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 18:57:16 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	st_clear(t_stack **st, void (*del)(void *))
{
	t_stack	*current;
	t_stack	*next;

	if (!st || !del)
		return ;
	current = *st;
	next = *st;
	while (next)
	{
		current = next;
		next = current->next;
		free(current);
	}
	*st = NULL;
}
