/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:36:20 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/12 18:58:06 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	st_add_front(t_stack **st, t_stack *new)
{
	new->next = *st;
	*st = new;
}

// void	print_t_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// t_list	*ft_lstnew(void *content);

// int	main(int ac, char **av)
// {
// 	t_list	*squid;
// 	t_list	*new;

// 	ac = 0;
// 	squid = ft_lstnew(av[1]);
// 	print_t_list(squid);
// 	new = ft_lstnew(av[2]);
// 	ft_lstadd_front(&squid, new);
// 	print_t_list(squid);
// }
