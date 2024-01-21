/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:55:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/21 22:58:43 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_and_check(t_tuple *t, char *line)
{
	// strncmp to ops\n all w
	// or Error exit
	return (0);
}

void	checker(t_tuple *t)
{
    char *operation;

	operation = get_next_line(0);
	while (operation)
	{
		if !(exec_and_check(operation))
			return(t_clean(t), free(operation), v_printf(Error\n), exit(1));
		free(operation);
		operation = get_next_line(0);
	}
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