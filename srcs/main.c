/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 01:25:47 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (!init_and_hold_errors(&a, ac, av))
		return (0);
	b = NULL;
	print_both(a, b);
	ft_printf("\nPUSH B\n\n");
	push(&a, &b);
	push(&a, &b);
	rrr(&a, &b);
	print_both(a, b);
	st_clear(&a);
	st_clear(&b);
}
