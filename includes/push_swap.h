/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:00:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/16 19:23:31 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "QuoicouLibft/libft.h"
# include "stdbool.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

// String Utils
void				free_split(char **split);
void				print_split(const char **split);

// Stack
typedef struct s_stack
{
	int				nb;
	size_t			pos;
	size_t			push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// Errors Holding
bool				init_and_hold_errors(t_stack **a, t_stack **b, int ac,
						char **av);
bool				is_whitespace(char c);
bool				is_valid_int(const char *s);
bool				is_valid_string(const char *s);
bool				is_there_a_double(t_stack *st);
char				*str_whitespaces(void);
char				**create_args(const char *s);
void				free_args(char **args, int are_args_a_string);

// Both Stacks;
typedef struct s_tuple
{
	t_stack			*a;
	t_stack			*b;
}					t_tuple;

// Stack & Tuple Utils
void				st_add_back(t_stack **stack, t_stack *new);
void				st_add_front(t_stack **st, t_stack *new);
void				st_clear(t_stack **st);
t_stack				*st_new(int nb, int pos);
size_t				st_size(t_stack *st);
void				st_print(t_stack *st);
void				t_print(t_tuple t);
void				t_clear(t_tuple *t);

// Stacks Operations
void				swap(t_stack *st);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **st);
void				rrotate(t_stack **st);

// Literal Operations
void				sa(t_tuple t);
void				sb(t_tuple t);
void				ss(t_tuple t);
void				pa(t_tuple *t);
void				pb(t_tuple *t);
void				ra(t_tuple *t);
void				rb(t_tuple *t);
void				rr(t_tuple *t);
void				rra(t_tuple *t);
void				rrb(t_tuple *t);
void				rrr(t_tuple *t);

// Sort
bool				is_sorted(t_stack *st);
void				sort_2(t_tuple *t);
void				sort_3(t_tuple *t);
void				turkish_algo(t_tuple *t);

#endif