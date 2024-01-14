/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 20:49:04 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_tuple	t;

	if (!init_and_hold_errors(&t.a, ac, av))
		return (0);
	t.b = NULL;
	t_print(t);
	pb(&t);
	pb(&t);
	pb(&t);
	rrr(&t);
	ra(&t);
	t_print(t);
	t_clear(&t);
}
