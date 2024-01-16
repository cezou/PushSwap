/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:31:53 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/16 15:58:24 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

// Creates a String (char *) with all whitespaces
// (to use it with split charset after)
char	*str_whitespaces(void)
{
	char	*whitespaces;
	size_t	i;

	whitespaces = malloc(sizeof(char) * 7);
	if (!whitespaces)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		whitespaces[i] = i + 9;
		i++;
	}
	whitespaces[i++] = ' ';
	whitespaces[i] = 0;
	return (whitespaces);
}

void	print_split(const char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		ft_printf("%s", split[i++]);
		if (split[i])
			ft_printf(" ");
		else
			ft_printf("\n");
	}
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_args(char **args, int are_args_a_string)
{
	if (!are_args_a_string)
		return ;
	free_split(args);
}
