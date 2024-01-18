/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 14:33:21 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_algo(t_tuple *t)
{
	if (st_size(t->a) <= 1 || is_sorted(t->a))
		return ;
	if (st_size(t->a) == 2)
		return (sort_2(t));
	if (st_size(t->a) == 3)
		return (sort_3(t));
	turkish_algo(t);
}

int	main(int ac, char **av)
{
	t_tuple	t;

	if (ac <= 1)
		return (0);
	if (!init_and_hold_errors(&t.a, &t.b, ac, av))
		return (0);
	// t_print(t);
	sort_algo(&t);
	// t_print(t);
	t_clear(&t);
}
