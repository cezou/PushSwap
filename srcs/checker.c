/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:55:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/22 16:44:08 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/push_swap.h"

bool	ops_cmp(char *op, char *expected)
{
	if (ft_strlen(op) == ft_strlen(expected) && !ft_strncmp(op, expected,
			ft_strlen(op)))
		return (1);
	return (0);
}

bool	exec_and_check(t_tuple *t, char *op)
{
	if (ops_cmp(op, "sa\n"))
		return (sa(*t, 0), 1);
	if (ops_cmp(op, "sb\n"))
		return (sb(*t, 0), 1);
	if (ops_cmp(op, "ss\n"))
		return (ss(*t, 0), 1);
	if (ops_cmp(op, "pa\n"))
		return (pa(t, 0), 1);
	if (ops_cmp(op, "pb\n"))
		return (pb(t, 0), 1);
	if (ops_cmp(op, "ra\n"))
		return (ra(t, 0), 1);
	if (ops_cmp(op, "rb\n"))
		return (rb(t, 0), 1);
	if (ops_cmp(op, "rr\n"))
		return (rr(t, 0), 1);
	if (ops_cmp(op, "rra\n"))
		return (rra(t, 0), 1);
	if (ops_cmp(op, "rrb\n"))
		return (rrb(t, 0), 1);
	if (ops_cmp(op, "rrr\n"))
		return (rrr(t, 0), 1);
	return (0);
}

void	checker(t_tuple *t)
{
	char	*operation;

	operation = get_next_line(STDIN);
	while (operation)
	{
		if (!exec_and_check(t, operation))
			return (t_clear(t), free(operation), v_printf("Error\n"), exit(1));
		free(operation);
		operation = get_next_line(STDIN);
	}
	if (!t->a)
		return (v_printf("KO\n"));
	if (is_sorted(t->a) && !t->b)
		return (v_printf("OK\n"));
	ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_tuple	t;

	if (ac <= 1)
		return (0);
	if (!init_and_handle_errors(&t.a, &t.b, ac, av))
		return (0);
	checker(&t);
	t_clear(&t);
}
