/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:08:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:40:39 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_node **n)
{
	int		max;
	int		max_index;
	int		i;
	t_node	*current;

	current = *n;
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

int	find_max_value(t_node **n)
{
	int		max;
	t_node	*current;

	if (n == NULL || *n == NULL)
		return (INT_MIN);
	current = *n;
	max = current->value;
	while(current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_min_value(t_node **n)
{
	int		min;
	t_node	*current;

	if (n == NULL || *n == NULL)
		return (INT_MAX);
	current = *n;
	min = current->value;
	while(current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}
