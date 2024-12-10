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
	int		value;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*list;
	int		length;
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
void init_t_lists(t_list *list_a, t_list *list_b, int argc, char **argv);
// ================ //

void	free_t_list(t_list list);

void	turk_algorithm(t_list *list_a, t_list *list_b);
t_node	*ft_list_to_node(t_list *list, int argc, char **argv);
int		find_closest_smaller_index(int value, t_list list);
int		find_closest_bigger_index(int value, t_list list);
t_move	calculate_smallest_move_cost(t_list from, t_list target, int (*func)(int, t_list));
void	sort(t_list *list_a, t_list *list_b, int (*sm_cost)(int, t_list));
void	sort_3(t_list *list);

int		ft_atoi(const char *nptr);

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
#endif