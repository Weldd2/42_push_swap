/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:56 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 18:56:42 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_node **b)
{
	int		max;
	int		max_index;
	int		i;
	t_node	*current;

	current = *b;
	max = current->value;
	max_index = 0;
	i = 0;
	while(current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

int	find_closest_smaller_index_in_b(int value, t_node **b)
{
	int		closest_smaller;
	int		closest_smaller_index;
	int		i;
	t_node	*current;
	int		found;

	current = *b;
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
		return (find_max_index(b));
	return (closest_smaller_index);
}

void	turk_algorithm(t_list **list_a, t_list **list_b)
{
	while((*list_a)->list)
		push(list_a, list_b);
	int value = 7;
	int closest = find_closest_smaller_index_in_b(value, &(*list_b)->list);
}
