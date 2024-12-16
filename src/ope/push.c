/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:55:41 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 20:08:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_t_list_update_to(t_list *l_to)
{
	int	moved_value;

	if (l_to == NULL || l_to->head == NULL)
		return ;
	moved_value = l_to->head->value;
	if (moved_value > l_to->max)
		l_to->max = moved_value;
	if (moved_value < l_to->min)
		l_to->min = moved_value;
	l_to->length++;
}

static void	push_t_list_update_from(t_list *l_from, t_list *l_to)
{
	int	moved_value;

	if (l_from == NULL || l_to == NULL)
		return ;
	moved_value = l_to->head->value;
	if (moved_value > l_from->max)
		l_from->max = find_max_value(l_from->head);
	if (moved_value == l_from->min)
		l_from->min = find_min_value(l_from->head);
	if (l_from->length > 0)
		l_from->length--;
}

void	push(t_list *l_from, t_list *l_to)
{
	t_node	*temp;
	t_node	**from;
	t_node	**to;

	from = &(l_from->head);
	to = &(l_to->head);
	if (from == NULL || to == NULL || *from == NULL)
		return ;
	temp = *to;
	*to = *from;
	*from = (*to)->next;
	(*to)->next = temp;
	push_t_list_update_to(l_to);
	push_t_list_update_from(l_from, l_to);
	write(1, "p", 1);
	write(1, l_to->name, 1);
	write(1, "\n", 1);
}
