/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/12 15:08:49 by antoinemura      ###   ########.fr       */
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
	write(1, "s", 1);
	write(1, list->name, 1);
	write(1, "\n", 1);
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
	write(1, "r", 1);
	write(1, list->name, 1);
	write(1, "\n", 1);
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
	write(1, "rr", 2);
	write(1, list->name, 1);
	write(1, "\n", 1);
}

void	rotate_ab(t_list *a, t_list *b)
{
	t_node	*first;
	t_node	*last;

	if (a != NULL && a->list != NULL && a->list->next != NULL)
	{
		first = a->list;
		last = first;
		while (last->next != NULL)
			last = last->next;
		a->list = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (b != NULL && b->list != NULL && b->list->next != NULL)
	{
		first = b->list;
		last = first;
		while (last->next != NULL)
			last = last->next;
		b->list = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}

void	rrotate_ab(t_list *a, t_list *b)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (a != NULL && a->list != NULL && a->list->next != NULL)
	{
		first = a->list;
		before_last = first;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = first;
		a->list = last;
	}
	if (b != NULL && b->list != NULL && b->list->next != NULL)
	{
		first = b->list;
		before_last = first;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = first;
		b->list = last;
	}
	write(1, "rrr\n", 4);
}
