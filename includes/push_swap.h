/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:00:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/22 15:34:39 by cviegas          ###   ########.fr       */
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
	bool			is_above_median;
	bool			is_cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

// Errors Holding
bool				init_and_handle_errors(t_stack **a, t_stack **b, int ac,
						char **av);
bool				one_arg(int *are_args_a_string, char ***args, int ac,
						char **av);
bool				is_whitespace(char c);
bool				is_valid_int(const char *s);
size_t				skip_i_and_sign(const char *s, int *sign,
						bool *is_there_plus);
bool				check_relou_nbrs(const char *s, long long int atonb);
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
t_stack				*st_new(int nb, int pos);
void				st_add_back(t_stack **stack, t_stack *new);
void				st_add_front(t_stack **st, t_stack *new);
size_t				st_size(t_stack *st);
t_stack				*st_max(t_stack *st);
t_stack				*st_min(t_stack *st);
void				st_clear(t_stack **st);
void				st_print(t_stack *st);
void				t_print(t_tuple t);
void				t_clear(t_tuple *t);

// Stacks Operations
void				swap(t_stack *st);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **st);
void				rrotate(t_stack **st);

// Literal Operations
void				sa(t_tuple t, bool print_or_not);
void				sb(t_tuple t, bool print_or_not);
void				ss(t_tuple t, bool print_or_not);
void				pa(t_tuple *t, bool print_or_not);
void				pb(t_tuple *t, bool print_or_not);
void				ra(t_tuple *t, bool print_or_not);
void				rb(t_tuple *t, bool print_or_not);
void				rr(t_tuple *t, bool print_or_not);
void				rra(t_tuple *t, bool print_or_not);
void				rrb(t_tuple *t, bool print_or_not);
void				rrr(t_tuple *t, bool print_or_not);

// SORT
void				sort_algo(t_tuple *t);
void				turkish_algo(t_tuple *t);
bool				is_sorted(t_stack *st);
void				sort_2(t_tuple *t);
void				sort_3(t_tuple *t);

// Init before Moves
void				init_stacks_a(t_tuple *t);
void				set_pos_and_median(t_stack *st);
void				set_target_a(t_tuple *t);
void				set_push_costs_a(t_tuple *t);
void				set_cheapest_a(t_tuple *t);
void				init_stacks_b(t_tuple *t);
void				set_target_b(t_tuple *t);

typedef struct s_cheapest
{
	int				target_nb;
	int				cheapest_nb;
	bool			cheapest_is_above;
	bool			target_is_above;
}					t_cheapest;

// MOVE
void				move_cheapest_to_b(t_tuple *t);
void				move_to_a(t_tuple *t);

#endif