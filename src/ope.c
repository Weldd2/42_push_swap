/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:02:43 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **l)
{
	t_node	**n; 
	t_node	*temp;
	t_node	*next_value;

	n = &((*l)->list);
	if (n == NULL || (*n) == NULL || (*n)->next == NULL)
		return ;
	temp = (*n);
	next_value = (*n)->next->next;
	(*n) = (*n)->next;
	(*n)->next = temp;
	(*n)->next->next = next_value;
}

void	push_t_list_update_to(t_list **l_from, t_list **l_to)
{
	if ((*l_from)->list->value > (*l_to)->max)
		(*l_to)->max = (*l_from)->list->value;
	if ((*l_from)->list->value < (*l_to)->min)
		(*l_to)->min = (*l_from)->list->value;
}

void	push_t_list_update_from(t_list **l_from, t_list **l_to)
{
	if ((*l_to)->list->value > (*l_from)->max)
		(*l_from)->max = find_max_value(&(*l_from)->list);
	if ((*l_to)->list->value == (*l_from)->min)
		(*l_from)->min = find_min_value(&(*l_from)->list);
}

void	push(t_list **l_from, t_list **l_to)
{
	t_node	*temp;
	t_node	**from; 
	t_node	**to;

	from = &((*l_from)->list);
	to = &((*l_to)->list);
	push_t_list_update_to(l_from, l_to);
	if (from == NULL || to == NULL || *from == NULL)
		return ;
	temp = *to;
	*to = *from;
	*from = (*to)->next;
	(*to)->next = temp;
	push_t_list_update_from(l_from, l_to);
	(*l_from)->length--;
	(*l_to)->length++;
}

void	rotate(t_list **list)
{
	t_node	*before_last;
	t_node	*first;
	t_node	**n;

	n = &(*list)->list;
	if (n == NULL || (*n) == NULL)
		return ;
	first = *n;
	before_last = *n;
	while (before_last->next->next)
		before_last = before_last->next;
	*n = before_last->next;
	(*n)->next = first;
	before_last->next = NULL;
}

void	rrotate(t_list **list)
{
	t_node	*second;
	t_node	*last;
	t_node	**n;

	n = &(*list)->list;
	if (n == NULL || (*n) == NULL)
		return ;
	second = (*n)->next;
	last = *n;
	while(last->next)
		last = last->next;
	(*n)->next = NULL;
	last->next = *n;
	*n = second;
}
