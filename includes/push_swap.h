/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:39:31 by sinlee            #+#    #+#             */
/*   Updated: 2023/07/16 04:11:27 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// Stack Utilties
t_node				*last_first_node(t_node *node, bool is_last);
t_node				*add_node(t_node *node, int content);
t_node				*create_node(int content);
void				clear_lst_node(t_node *node);
void				print_stack(t_node *stack, char *str, bool advanced,
						bool to_first);
int					stack_len(t_node *stack);
int					min(int a, int b);
int					max(int a, int b);

// push swap operations
bool				swap(t_node **stack);
bool				push(t_node **stack_from, t_node **stack_to);
bool				rotate(t_node **stack, bool reverse);
bool				execute(t_node **stack_a, t_node **stack_b, char *line,
						bool s_print);
int					execute_calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
int					reverse_calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
bool				multi_execute(t_node **stack_a, t_node **stack_b,
						char *line, int n);
void				check_exit_else_exec(t_node **stack_a, t_node **stack_b,
						char *line);
void				exec_smt(t_node **stack_a, t_node **stack_b, int pos[2],
						int mode);
void				execute_ps(t_node **stack_a, t_node **stack_b, int pos[2],
						int mode);
void				reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2]);

// sorting Utilities
void				push_swap(t_node *stack_a, t_node *stack_b, int len);
bool				is_sorted(t_node *stack, bool reverse);
int					min_max_pos(t_node *stack, bool max, bool pos);
int					find_target(t_node *stack_from, t_node *stack_to);
void				target_push(t_node *stack, int pos);
void				min_max_push(t_node *stack, bool max);
int					calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
int					lcm(int pos[2], int len_a, int len_b, bool return_move);
int					node_index(t_node *stack, int target);
int					find_min_index(t_node *stack_a, t_node *stack_b, int len);
void				sort_three(t_node *stack_a);
void				reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2]);

// generic Utilities
int					ft_strcmp(const char *s1, const char *s2);
void				ft_error(t_node *stack_a);
int					ft_atoi_ps(char *str, t_node *stack_a);
bool				is_valid(t_node *stack_a, char *str);

#endif