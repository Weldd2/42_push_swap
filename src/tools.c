/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:46 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 18:09:48 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list list, char *name)
{
	t_node	*current;

	current = list.list;
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

	current = list.list;
	i = 0;
	while(current->next && i != index )
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	is_sorted(t_list list)
{
	t_node	*current;
	int		prev;
	int		count;

	count = 0;
	current = list.list;
	prev = current->value;
	while(current)
	{
		if (current->value < prev)
			count++;
		prev = current->value;
		current = current->next;
	}
	if (list.list->value < prev)
		count++;
	if (count > 1)
		return (1);
	return (0);
}

int	is_reverse_sorted(t_list list)
{
	t_node	*current;
	int		prev;
	int		count;

	count = 0;
	current = list.list;
	prev = current->value;
	while(current)
	{
		if (current->value > prev)
			count++;
		prev = current->value;
		current = current->next;
	}
	if (list.list->value > prev)
		count++;
	if (count > 1)
		return (1);
	return (0);
}
