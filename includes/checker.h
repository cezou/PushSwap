/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:55 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 17:59:01 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define STDIN 0
# include "push_swap.h"

bool	init_and_handle_errors_check(t_stack **a, t_stack **b, int ac,
			char **av);

#endif