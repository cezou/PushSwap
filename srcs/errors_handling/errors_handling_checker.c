/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:34 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 18:12:34 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	one_arg(int *are_args_a_string, char ***args, int ac, char **av)
{
	*are_args_a_string = 0;
	if (ac == 2)
	{
		if (is_valid_int(av[1]))
		{
			*args = create_args(av[1]);
			*are_args_a_string = 1;
			return (1);
		}
		if (!is_valid_string(av[1]))
			return (v_printf("Error\n"), 0);
		*args = create_args(av[1]);
		*are_args_a_string = 1;
	}
	else
		*args = av + 1;
	return (1);
}

bool	init_and_handle_errors_check(t_stack **a, t_stack **b, int ac,
		char **av)
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
				v_printf("Error\n"), 0);
		st_add_back(a, st_new(ft_atoi(args[i]), i));
		i++;
	}
	if (is_there_a_double(*a))
		return (free_args(args, are_args_a_string), st_clear(a),
			v_printf("Error\n"), 0);
	free_args(args, are_args_a_string);
	return (1);
}
