/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:56 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/10 18:31:03 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_smaller_index(int value, t_list list)
{
	int		closest_smaller;
	int		closest_smaller_index;
	int		i;
	t_node	*current;
	int		found;

	current = list.list;
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
		return (find_max_index(list.list));
	return (closest_smaller_index);
}

int	find_closest_bigger_index(int value, t_list list)
{
	int		closest_bigger;
	int		closest_bigger_index;
	int		i;
	t_node	*current;
	int		found;

	current = list.list;
	i = 0;
	found = 0;
	closest_bigger = INT_MAX;
	closest_bigger_index = 0;
	while(current)
	{
		if (current->value > value && current->value < closest_bigger)
		{
			closest_bigger = current->value;
			closest_bigger_index = i;
			found = 1;
		}
		current = current->next;
		i++;
	}
	if (found == 0)
		return (find_min_index(list.list));
	return (closest_bigger_index);
}


t_move	calculate_smallest_move_cost(t_list from, t_list target, int (*func)(int, t_list))
{
	t_node	*current;
	int		cost;
	int		target_index;
	int		min_cost;
	int		i;
	t_move	move;

	current = from.list;
	min_cost = INT_MAX;
	i = 0;
	while (current)
	{
		target_index = func(current->value, target);
		cost = target_index + i;
		if (cost < min_cost)
		{
			move.elem_index = i;
			move.elem_value = current->value;
			move.target_index = target_index;
			move.target_value = get_elem_by_index(target, target_index);
			min_cost = cost;
		}
		current = current->next;
		i++;
	}
	return (move);
}

void	sort(t_list *from, t_list *to, int (*sm_cost)(int, t_list))
{
	t_move	move;

	move = calculate_smallest_move_cost(*from, *to, sm_cost);
	while(from->list->value != move.elem_value)
		rotate(from);
	while(to->list->value != move.target_value)
		rotate(to);
	push(from, to);
}

void	sort_3(t_list *list)
{
	int	first;
	int	second;
	int	third;
	
	first = list->list->value;
	second = list->list->next->value;
	third = list->list->next->next->value;

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

void	turk_algorithm(t_list *list_a, t_list *list_b)
{
	push(list_a, list_b);
	push(list_a, list_b);
	while(list_a->length > 3)
		sort(list_a, list_b, find_closest_smaller_index);
	sort_3(list_a);
	while(list_b->length > 0)
		sort(list_a, list_b, find_closest_bigger_index);
}
