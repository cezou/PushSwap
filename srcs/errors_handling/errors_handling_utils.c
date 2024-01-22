/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:13:33 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 15:18:45 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	skip_i_and_sign(const char *s, int *sign, bool *is_there_plus)
{
	size_t	i;

	i = 0;
	*sign = 1;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '+')
	{
		i++;
		*is_there_plus = 1;
	}
	else if (s[i] == '-')
	{
		*sign = -1;
		i++;
	}
	return (i);
}

size_t	number_of_0(const char *s, bool *is_there_plus)
{
	size_t	nb_zero;
	size_t	i;
	int		sign;

	nb_zero = 0;
	*is_there_plus = 0;
	i = skip_i_and_sign(s, &sign, is_there_plus) - 1;
	while (s[++i] == '0')
		nb_zero++;
	return (nb_zero);
}

bool	check_relou_nbrs(const char *s, long long int atonb)
{
	size_t	nb_zero;
	char	*ltoa;
	bool	is_there_plus;

	nb_zero = number_of_0(s, &is_there_plus);
	ltoa = ft_ltoa(atonb);
	ft_printf("len - 0s + sign :%d\n", ft_strlen(s) - nb_zero + is_there_plus);
	ft_printf("len(itoa) : %d\n", ft_strlen(ltoa));
	if (ft_strlen(s) - nb_zero != ft_strlen(ltoa) + is_there_plus)
		return (free(ltoa), 0);
	return (free(ltoa), 1);
}

bool	is_valid_int(const char *s)
{
	long long int	atonb;
	size_t			i;
	int				sign;
	bool			voidb;

	if (!s || !s[0])
		return (0);
	atonb = 0;
	i = skip_i_and_sign(s, &sign, &voidb);
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
	if (atonb >= MIN_INT && atonb <= MAX_INT && check_relou_nbrs(s, atonb))
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

	if (!s[0] || !s)
		return (0);
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
