/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:37:47 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 02:01:51 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

t_node	*ft_list_to_node(t_list *list, int argc, char **argv)
{
	int		i;
	t_node	*current;
	t_node	*prev;
	int		value;

	i = argc - 1;
	list->length = i;
	prev = NULL;
	while (i >= 1)
	{
		value = ft_atoi(argv[i]);
		if (value > list->max)
			list->max = value;
		if (value < list->min)
			list->min = value;
		current = ft_init_node(value);
		current->next = prev;
		prev = current;
		i--;
	}
	return (current);
}
