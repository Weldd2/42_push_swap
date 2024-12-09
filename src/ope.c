/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 19:31:48 by antoinemura      ###   ########.fr       */
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
	write(1, "swap\n", 6);
}

void	push_t_list_update_to(t_list *l_to)
{
	int	moved_value;

	if (l_to == NULL || l_to->list == NULL)
		return;
	moved_value = l_to->list->value;
	if (moved_value > l_to->max)
		l_to->max = moved_value;
	if (moved_value < l_to->min)
		l_to->min = moved_value;
	l_to->length++;
}

void	push_t_list_update_from(t_list *l_from, t_list *l_to)
{
	int	moved_value;

	if (l_from == NULL || l_to == NULL)
		return;
	moved_value = l_to->list->value;
	if (moved_value > l_from->max)
		l_from->max = find_max_value(l_from->list);
	if (moved_value == l_from->min)
		l_from->min = find_min_value(l_from->list);
		
	if (l_from->length > 0)
		l_from->length--;
}

void	push(t_list *l_from, t_list *l_to)
{
	t_node	*temp;
	t_node	**from; 
	t_node	**to;

	from = &(l_from->list);
	to = &(l_to->list);
	if (from == NULL || to == NULL || *from == NULL)
		return ;
	temp = *to;
	*to = *from;
	*from = (*to)->next;
	(*to)->next = temp;
	push_t_list_update_to(l_to);
	push_t_list_update_from(l_from, l_to);
	write(1, "push\n", 6);
}

void rotate(t_list *list)
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
	write(1, "rotate\n", 8);
}

void rrotate(t_list *list)
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
	write(1, "rrotate\n", 9);
}

