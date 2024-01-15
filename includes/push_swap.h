/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:00:24 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/15 19:36:32 by cviegas          ###   ########.fr       */
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

// Both Stacks;
typedef struct s_tuple
{
	t_stack			*a;
	t_stack			*b;
}					t_tuple;

// Stack Operations
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

// Stack & Tuple Utils
void				st_add_back(t_stack **stack, t_stack *new);
void				st_add_front(t_stack **st, t_stack *new);
void				st_clear(t_stack **st);
t_stack				*st_new(int nb, int pos);
size_t				st_size(t_stack *st);
void				st_print(t_stack *st);
void				t_print(t_tuple t);
void				t_clear(t_tuple *t);

// Errors Holding
int					init_and_hold_errors(t_stack **a, t_stack **b, int ac,
						char **av);
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