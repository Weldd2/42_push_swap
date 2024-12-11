/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 13:22:45 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list)
{
	t_node	*n;
	t_node	*temp;
	t_node	*next_value;

	if (list == NULL)
		return ;
	n = list->list;
	if (n == NULL || n->next == NULL)
		return ;
	temp = n;
	next_value = n->next->next;
	n = n->next;
	n->next = temp;
	temp->next = next_value;
	list->list = n;
	write(1, "sa\n", 4);
}

void	rotate(t_list *list)
{
	t_node	*first;
	t_node	*last;

	if (list == NULL)
		return ;
	first = list->list;
	if (first == NULL || first->next == NULL)
		return ;
	last = first;
	while (last->next)
		last = last->next;
	list->list = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 4);
}

void	rrotate(t_list *list)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (list == NULL)
		return ;
	first = list->list;
	if (first == NULL || first->next == NULL)
		return ;
	before_last = first;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	list->list = last;
	write(1, "rra\n", 5);
}
