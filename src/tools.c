/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:46 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 22:09:48 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list, char *name)
{
	t_node	*current;

	current = list->list;
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

int	get_elem_by_index(t_list *list, int index)
{
	t_node	*current;
	int		i;

	current = list->list;
	i = 0;
	while(i != index)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	is_sorted(t_list *list)
{
	t_node	*current;
	int		prev;

	current = list->list;
	prev = current->value;
	while(current)
	{
		if (current->value < prev && current->value != list->min)
			return (1);
		prev = current->value;
		current = current->next;
	}
	return (0);
}
