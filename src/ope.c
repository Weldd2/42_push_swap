/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:49:45 by antoinemura      ###   ########.fr       */
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
	n = list->head;
	if (n == NULL || n->next == NULL)
		return ;
	temp = n;
	next_value = n->next->next;
	n = n->next;
	n->next = temp;
	temp->next = next_value;
	list->head = n;
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
	first = list->head;
	if (first == NULL || first->next == NULL)
		return ;
	last = first;
	while (last->next)
		last = last->next;
	list->head = first->next;
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
	first = list->head;
	if (first == NULL || first->next == NULL)
		return ;
	before_last = first;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	list->head = last;
	write(1, "rr", 2);
	write(1, list->name, 1);
	write(1, "\n", 1);
}

void	rotate_ab(t_list *a, t_list *b)
{
	t_node	*first;
	t_node	*last;

	if (a != NULL && a->head != NULL && a->head->next != NULL)
	{
		first = a->head;
		last = first;
		while (last->next != NULL)
			last = last->next;
		a->head = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (b != NULL && b->head != NULL && b->head->next != NULL)
	{
		first = b->head;
		last = first;
		while (last->next != NULL)
			last = last->next;
		b->head = first->next;
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

	if (a != NULL && a->head != NULL && a->head->next != NULL)
	{
		first = a->head;
		before_last = first;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = first;
		a->head = last;
	}
	if (b != NULL && b->head != NULL && b->head->next != NULL)
	{
		first = b->head;
		before_last = first;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = first;
		b->head = last;
	}
	write(1, "rrr\n", 4);
}
