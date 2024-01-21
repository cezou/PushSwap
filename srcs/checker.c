/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:55:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/21 22:04:11 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void checker(t_tuple *t)
{
    
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