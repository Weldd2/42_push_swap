/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:04:03 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/17 18:07:57 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_node(int value)
{
	t_node	*n;

	n = mem_arena_alloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	init_t_nodes(t_list *list_a, int *values, int nb_val)
{
	t_node	*prev;

	while (nb_val > 0)
	{
		prev = list_a->head;
		list_a->head = ft_init_node(values[nb_val - 1]);
		list_a->head->next = prev;
		nb_val--;
	}
	if (list_a == NULL)
		ft_error();
}

void	init_t_lists(t_list *list_a, t_list *list_b, int *values, int nb_val)
{
	list_a->head = NULL;
	list_a->min = INT_MAX;
	list_a->max = INT_MIN;
	list_a->length = 0;
	list_a->name = "a";
	list_b->head = NULL;
	list_b->min = INT_MAX;
	list_b->max = INT_MIN;
	list_b->length = 0;
	list_b->name = "b";
	init_t_nodes(list_a, values, nb_val);
	list_a->length = nb_val;
	list_a->max = find_max_value(list_a->head);
	list_a->min = find_min_value(list_a->head);
}

/*
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN || 
			has_duplicate(current, (int)value) == true)
			ft_error();
*/
