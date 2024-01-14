/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:00:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/14 01:23:26 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "QuoicouLibft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

// Stack
typedef struct s_stack
{
	int				nb;
	size_t			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Operations
void				swap(t_stack *st);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **st);
void				rr(t_stack **a, t_stack **b);
void				rrotate(t_stack **st);
void				rrr(t_stack **a, t_stack **b);

// Stack Utils
void				st_add_back(t_stack **stack, t_stack *new);
void				st_add_front(t_stack **st, t_stack *new);
void				st_clear(t_stack **st);
t_stack				*st_new(int nb, int pos);
size_t				st_size(t_stack *st);
void				st_print(t_stack *st);
void				print_both(t_stack *a, t_stack *b);

// Errors Holding
int					init_and_hold_errors(t_stack **stack_a, int ac, char **av);
int					is_whitespace(char c);
int					is_valid_int(const char *s);
int					is_valid_string(const char *s);
int					is_there_a_double(t_stack *st);
char				*str_whitespaces(void);
char				**create_args(const char *s);

// String Utils
void				free_split(char **split);
void				print_split(const char **split);
void				free_args(char **args, int are_args_a_string);

#endif