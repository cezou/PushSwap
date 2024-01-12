/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 23:11:55 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_there_a_double(t_stack *st)
{
	t_stack	*start;
	int		temp;
	int		pos;

	start = st;
	while (start)
	{
		temp = st->nb;
		pos = st->pos;
		while (st)
		{
			if (st->pos != pos && temp == st->nb)
				return (1);
			st = st->next;
		}
		st = start->next;
		start = start->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	char	**args;
	int		are_args_a_string;
	size_t	i;

	are_args_a_string = 0;
	if (ac == 2)
	{
		if (is_valid_int(av[1]))
			return (0);
		if (!is_valid_string(av[1]))
			return ((void)ft_printf("Error\n"), 0);
		args = create_args(av[1]);
		are_args_a_string = 1;
	}
	else
		args = av + 1;
	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (free_args(args, are_args_a_string), st_clear(&stack_a),
				(void)ft_printf("Error\n"), 0);
		st_add_back(&stack_a, st_new(ft_atoi(args[i]), i));
		i++;
	}
	if (is_there_a_double(stack_a))
		return (free_args(args, are_args_a_string), st_clear(&stack_a),
			(void)ft_printf("Error\n"), 0);
	st_print(stack_a);
	free_args(args, are_args_a_string);
	st_clear(&stack_a);
}
