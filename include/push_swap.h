/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:49:33 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 17:43:54 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <str.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*list;
	int		length;
	char	*name;
	int		max;
	int		min;
}	t_list;

typedef struct s_move
{
	int	elem_index;
	int	elem_value;
	int	target_index;
	int	target_value;
}	t_move;

// ===== INIT ===== //
void	init_t_lists(t_list *list_a, t_list *list_b, int *values, int nb_val);
// ================ //

void	free_t_list(t_list list);

void	turk_algorithm(t_list *list_a, t_list *list_b);
t_node	*ft_list_to_node(t_list *list, int argc, char **argv);
int		find_closest_index(int value, t_list list, bool (*comp)(int, int, int));
t_move	get_best_move(t_list from, t_list target, bool (*comp)(int, int, int));
void	sort(t_list *list_a, t_list *list_b, bool (*comp)(int, int, int));
void	sort_3(t_list *list);
void	parse_args(int argc, char **argv, t_list *list_a, t_list *list_b);

long long	ft_atoi(const char *nptr);
bool		has_duplicate(int *values, int nb_values, int value);

// ===== OPE ===== //
void	swap(t_list *list);
void	push(t_list *l_from, t_list *l_to);
void	rotate(t_list *list);
void	rrotate(t_list *list);
// =============== //

int		find_max_index(t_node *n);
int		find_max_value(t_node *n);
int		find_min_index(t_node *n);
int		find_min_value(t_node *n);
int		max(int a, int b);

void	print_list(t_list list, char *name);
int		get_elem_by_index(t_list list, int index);
bool	is_sorted(t_list list, int (*direction)(int, int));
int		descending(int a, int b);
int		ascending(int a, int b);
void	ft_error(void);
bool	comp_smaller(int current_value, int target_value, int closest);
bool	comp_bigger(int current_value, int target_value, int closest);

#endif