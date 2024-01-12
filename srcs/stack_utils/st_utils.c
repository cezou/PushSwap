/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 05:17:29 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 20:40:16 by cviegas          ###   ########.fr       */
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

void	st_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;
	t_stack	*next;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	current = *stack;
	next = *stack;
	while (next)
	{
		current = next;
		next = current->next;
	}
	current->next = new;
}

void	st_add_front(t_stack **st, t_stack *new)
{
	new->next = *st;
	*st = new;
}

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

void	st_clear(t_stack **st)
{
	t_stack	*current;
	t_stack	*next;

	if (!st)
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
