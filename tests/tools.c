/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:31:08 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/12 15:08:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void assertLinkedList(t_node *list, int *values, int length)
{
	t_node	*current;
	int		i;

	i = 0;
	current = list;
	while (current && i < length)
	{
		assert(values[i] == current->value);
		current = current->next;
		i++;
	}
	assert(current == NULL);
	assert(i == length);
}
