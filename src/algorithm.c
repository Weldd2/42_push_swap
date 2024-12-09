/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:56 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 02:43:31 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_smaller_index(int value, t_list *list)
{
	int		closest_smaller;
	int		closest_smaller_index;
	int		i;
	t_node	*current;
	int		found;

	current = list->list;
	i = 0;
	found = 0;
	closest_smaller = INT_MIN;
	closest_smaller_index = 0;
	while(current)
	{
		if (current->value < value && current->value > closest_smaller)
		{
			closest_smaller = current->value;
			closest_smaller_index = i;
			found = 1;
		}
		current = current->next;
		i++;
	}
	if (found == 0)
		return (find_max_index(&(list->list)));
	return (closest_smaller_index);
}

t_move	calculate_smallest_move_cost(t_list *a, t_list *b)
{
	t_node	*current_a;
	int		cost;
	int		target_index;
	int		min_cost;
	int		i;
	t_move	move;

	current_a = a->list;
	min_cost = INT_MAX;
	i = 0;
	while (current_a)
	{
		target_index = find_closest_smaller_index(current_a->value, b);
		cost = target_index + i;
		if (cost < min_cost)
		{
			move.a_index = i;
			move.b_index = target_index;
			min_cost = cost;
		}
		current_a = current_a->next;
		i++;
	}
	return (move);
}

void	sort(t_list **list_a, t_list **list_b)
{
	int		i;
	t_move	move;

	i = 0;
	move = calculate_smallest_move_cost(*list_a, *list_b);
	while(i < move.a_index)
	{
		rrotate(list_a);
		i++;
	}
	i = 0;
	while(i < move.b_index)
	{
		rrotate(list_b);
		i++;
	}
	push(list_a, list_b);
}

//b -> 1 2 4 5
//a -> 3 6 7 8
// tant que b n'a pas rotate du la valeur de l'index de b

void	sort_3(t_list **list)
{
	int	first;
	int	second;
	int	third;
	
	first = (*list)->list->value;
	second = (*list)->list->next->value;
	third = (*list)->list->next->next->value;

	if (first > second && second < third && first < third)
		swap(list);
	else if (first > second && second > third)
	{
		swap(list);
		rrotate(list);
	}
	else if (first > second && second < third && first > third)
		rotate(list);
	else if (first < second && second > third && first < third)
	{
		swap(list);
		rotate(list);
	}
	else if (first < second && second > third && first > third)
		rrotate(list);
}
// NORMAL
// SORTED 2 - 3 - 1
// SORTED 3 - 1 - 2
// SORTED 1 - 2 - 3
// 3 - 2 - 1
// 1 - 3 - 2
// 2 - 1 - 3

// REVERSE
// SORTED 3 - 2 - 1
// SORTED 2 - 1 - 3
// SORTED 1 - 3 - 2
// 1 - 2 - 3
// 3 - 1 - 2
// 2 - 3 - 1

void	turk_algorithm(t_list **list_a, t_list **list_b)
{
	while((*list_a)->length > 3)
		push(list_a, list_b);
	sort(list_a, list_b);
}
