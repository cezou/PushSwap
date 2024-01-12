/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 21:58:02 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**create_args(const char *s)
{
	char	*whitespaces;
	char	**args;

	whitespaces = str_whitespaces();
	if (!whitespaces)
		return (NULL);
	args = ft_split_charset(s, whitespaces);
	if (!args)
		return (free(whitespaces), NULL);
	free(whitespaces);
	return (args);
}

int	is_valid_string(const char *s)
{
	size_t	i;
	char	**args;

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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		are_args_a_string;
	char	**args;
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
		st_add_back(&stack_a, st_new(ft_atoi(args[i])));
		i++;
	}
	st_print(stack_a);
	free_args(args, are_args_a_string);
	st_clear(&stack_a);
}
