/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:58:38 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 18:58:37 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **n)
{
	t_node	*temp;
	t_node	*next_value;

	if (n == NULL || (*n) == NULL || (*n)->next == NULL)
		return ;
	temp = (*n);
	next_value = (*n)->next->next;
	(*n) = (*n)->next;
	(*n)->next = temp;
	(*n)->next->next = next_value;
}

void	push(t_node **from, t_node **to)
{
	t_node	*temp;

	if (from == NULL || to == NULL || *from == NULL)
		return ;
	temp = *to;
	*to = *from;
	*from = (*to)->next;
	(*to)->next = temp;
}

void	rotate(t_node **n)
{
	t_node	*before_last;
	t_node	*first;

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

void	rrotate(t_node **n)
{
	t_node	*second;
	t_node	*last;

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
