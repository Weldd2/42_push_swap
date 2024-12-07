#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define INT_MIN -2147483648;
# define INT_MAX 2147483647;

typedef struct s_node
{
	int		value;
	struct s_node	*next;
	// struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*list;
	int		median;
	int		max;
	int		min;
}	t_list;

void	init_t_lists(t_list **list_a, t_list **list_b);
void	init_t_nodes(t_node **a, t_node **b, int argc, char **argv);
void	turk_algorithm(t_list **list_a, t_list **list_b);
t_node	*ft_list_to_node(int argc, char **argv);

int		ft_atoi(const char *nptr);
void	swap(t_node **n);
void	push(t_node **from, t_node **to);
void	rotate(t_node **n);
void	rrotate(t_node **n);

#endif