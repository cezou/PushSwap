/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_holding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:13:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 20:37:01 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	skip_i_and_sign(const char *s, int *sign)
{
	size_t	i;

	i = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		*sign = -1;
		i++;
	}
	return (i);
}
int	is_valid_int(const char *s)
{
	long long int	atonb;
	size_t			i;
	int				sign;

	atonb = 0;
	sign = 1;
	i = skip_i_and_sign(s, &sign);
	while (s[i])
	{
		if (s[i] && !ft_isdigit(s[i]))
			return (0);
		atonb *= 10;
		atonb += s[i] - '0';
		i++;
	}
	atonb *= sign;
	if (atonb >= MIN_INT && atonb <= MAX_INT)
		return (1);
	return (0);
}
