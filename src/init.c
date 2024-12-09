/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:04:03 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 17:55:48 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_t_nodes(t_list *list_a, t_list *list_b, int argc, char **argv)
{
	list_a->list = ft_list_to_node(list_a, argc, argv);
	if (list_a->list == NULL)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	list_b->list = NULL;
}

void init_t_lists(t_list *list_a, t_list *list_b, int argc, char **argv)
{
	list_a->list = NULL;
	list_a->min = INT_MAX;
	list_a->max = INT_MIN;
	list_a->length = 0;
	list_b->list = NULL;
	list_b->min = INT_MAX;
	list_b->max = INT_MIN;
	list_b->length = 0;
	init_t_nodes(list_a, list_b, argc, argv);
}
