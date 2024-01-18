/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/18 17:47:25 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_tuple	t;

	if (ac <= 1)
		return (0);
	if (!init_and_handle_errors(&t.a, &t.b, ac, av))
		return (0);
	sort_algo(&t);
	t_clear(&t);
}
