/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_holding_and_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:47:45 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/15 19:36:01 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	one_arg(int *are_args_a_string, char ***args, int ac, char **av)
{
	*are_args_a_string = 0;
	if (ac == 2)
	{
		if (is_valid_int(av[1]))
			return (0);
		if (!is_valid_string(av[1]))
			return ((void)ft_printf("Error\n"), 0);
		*args = create_args(av[1]);
		*are_args_a_string = 1;
	}
	else
		*args = av + 1;
	return (1);
}

int	init_and_hold_errors(t_stack **a, t_stack **b, int ac, char **av)
{
	char	**args;
	int		are_args_a_string;
	size_t	i;

	if (!one_arg(&are_args_a_string, &args, ac, av))
		return (0);
	*a = NULL;
	*b = NULL;
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (free_args(args, are_args_a_string), st_clear(a),
				(void)ft_printf("Error\n"), 0);
		st_add_back(a, st_new(ft_atoi(args[i]), i));
		i++;
	}
	if (is_there_a_double(*a))
		return (free_args(args, are_args_a_string), st_clear(a),
			(void)ft_printf("Error\n"), 0);
	free_args(args, are_args_a_string);
	return (1);
}
