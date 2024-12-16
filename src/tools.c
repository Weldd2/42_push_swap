/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:46 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:31:11 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list list, char *name)
{
	t_node	*current;

	current = list.head;
	printf("%s -> ", name);
	while (current != NULL)
	{
		printf("%d", current->value);
		if (current->next != NULL)
			printf(" -> ");
		current = current->next;
	}
	printf("\n");
}

int	get_elem_by_index(t_list list, int index)
{
	t_node	*current;
	int		i;

	current = list.head;
	i = 0;
	while (current->next && i != index)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	ascending(int a, int b)
{
	return (a < b);
}

int	descending(int a, int b)
{
	return (a > b);
}

bool	is_sorted(t_list list, int (*direction)(int, int))
{
	t_node	*current;
	int		prev;
	int		breaks;

	if (!list.head)
		return (true);
	breaks = 0;
	current = list.head;
	prev = current->value;
	current = current->next;
	while (current)
	{
		if (!direction(prev, current->value))
			breaks++;
		prev = current->value;
		current = current->next;
	}
	if (!direction(prev, list.head->value))
		breaks++;
	return (breaks <= 1);
}
