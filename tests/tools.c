/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:31:08 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 23:59:22 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	assertEquals(char* attendu, char* obtenu)
{
	if (strcmp(attendu, obtenu) != 0)
	{
		fprintf(stderr, "Assertion échouée: attendu \"%s\", obtenu \"%s\"\n", attendu, obtenu);
		exit(EXIT_FAILURE);
	}
}

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
