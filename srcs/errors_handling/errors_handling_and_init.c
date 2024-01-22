/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_and_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:47:45 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 15:37:43 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	init_and_handle_errors(t_stack **a, t_stack **b, int ac, char **av)
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

bool	one_arg(int *are_args_a_string, char ***args, int ac, char **av)
{
	*are_args_a_string = 0;
	if (ac == 2)
	{
		if (is_valid_int(av[1]))
			return (0);
		if (!is_valid_string(av[1]))
			return (v_printf("Error\n"), 0);
		*args = create_args(av[1]);
		*are_args_a_string = 1;
	}
	else
		*args = av + 1;
	return (1);
}

bool	is_valid_int(const char *s)
{
	long long int	atonb;
	size_t			i;
	int				sign;
	bool			voidb;

	if (!s || !s[0])
		return (0);
	atonb = 0;
	i = skip_i_and_sign(s, &sign, &voidb);
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		atonb *= 10;
		atonb += s[i] - '0';
		i++;
	}
	atonb *= sign;
	if (atonb >= MIN_INT && atonb <= MAX_INT && check_relou_nbrs(s, atonb))
		return (1);
	return (0);
}

bool	is_valid_string(const char *s)
{
	size_t	i;
	char	**args;

	if (!s[0] || !s)
		return (0);
	args = create_args(s);
	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (free_split(args), 0);
		i++;
	}
	free_split(args);
	return (1);
}
