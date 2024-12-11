/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:56 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 19:18:45 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	comp_smaller(int current_value, int target_value, int closest)
{
	if (current_value < target_value && current_value > closest)
		return (true);
	return (false);
}

bool	comp_bigger(int current_value, int target_value, int closest)
{
	if (current_value > target_value && current_value < closest)
		return (true);
	return (false);
}

int	find_closest_index(int value, t_list list, bool (*comp)(int, int, int))
{
	int		i;
	int		found;
	int		closest;
	int		closest_index;
	t_node	*current;

	current = list.list;
	i = 0;
	found = 0;
	if (comp == comp_smaller)
		closest = INT_MIN;
	else
		closest = INT_MAX;
	closest_index = 0;
	while (current)
	{
		if (comp(current->value, value, closest))
		{
			closest = current->value;
			closest_index = i;
			found = 1;
		}
		current = current->next;
		i++;
	}
	if (found == 0)
	{
		if (comp == comp_smaller)
			return (find_max_index(list.list));
		if (comp == comp_bigger)
			return (find_min_index(list.list));
	}
	return (closest_index);
}

t_move	get_best_move(t_list from, t_list target, bool (*comp)(int, int, int))
{
	t_node	*current;
	int		cost;
	int		target_index;
	int		min_cost;
	int		i;
	t_move	move;

	current = from.list;
	min_cost = INT_MAX;
	if (target.length == 0 || from.length == 0)
		ft_error();
	i = 0;
	while (current)
	{
		target_index = find_closest_index(current->value, target, comp);
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

void	turk_algorithm(t_list *list_a, t_list *list_b)
{
	int	min_index;

	min_index = 0;
	if (is_sorted(*list_a, ascending))
		return ;
	while (list_b->length != 2 && list_a->length != 3)
		push(list_a, list_b);
	while (list_a->length > 3)
		sort(list_a, list_b, comp_smaller);
	sort_3(list_a);
	while (list_b->length > 0)
		sort(list_b, list_a, comp_bigger);
	min_index = find_min_index(list_a->list);
	while (list_a->list->value != list_a->min)
	{
		if (min_index > list_a->length / 2)
			rrotate(list_a);
		else
			rotate(list_a);
	}
}
