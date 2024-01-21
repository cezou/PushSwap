/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:13:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/21 21:53:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

bool	is_valid_int(const char *s)
{
	long long int	atonb;
	size_t			i;
	int				sign;

	if (!s || !s[0])
			return (0);
	atonb = 0;
	sign = 1;
	i = skip_i_and_sign(s, &sign);
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
	if (atonb >= MIN_INT && atonb <= MAX_INT)
		return (1);
	return (0);
}

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

bool	is_valid_string(const char *s)
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

bool	is_there_a_double(t_stack *st)
{
	t_stack	*start;
	int		temp;
	size_t	pos;

	start = st;
	while (start)
	{
		temp = st->nb;
		pos = st->pos;
		while (st)
		{
			if (st->pos != pos && temp == st->nb)
				return (1);
			st = st->next;
		}
		st = start->next;
		start = start->next;
	}
	return (0);
}
