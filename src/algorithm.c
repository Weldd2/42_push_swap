/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:56 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:45:09 by antoinemura      ###   ########.fr       */
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

void	turk_algorithm(t_list **list_a, t_list **list_b)
{
	while((*list_a)->list != NULL)
		push(list_a, list_b);
	int value = 3;
	int closest = find_closest_smaller_index(value, *list_b);
	printf("closest index = %d\n", closest);
}
