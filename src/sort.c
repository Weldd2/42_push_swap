/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:02:14 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 13:12:44 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *list)
{
	int	first;
	int	second;
	int	third;

	first = list->list->value;
	second = list->list->next->value;
	third = list->list->next->next->value;
	if (first > second && second < third && first < third)
		swap(list);
	else if (first > second && second > third)
	{
		swap(list);
		rrotate(list);
	}
	else if (first > second && second < third && first > third)
		rotate(list);
	else if (first < second && second > third && first < third)
	{
		swap(list);
		rotate(list);
	}
	else if (first < second && second > third && first > third)
		rrotate(list);
}

void	sort(t_list *from, t_list *to, bool (*comp)(int, int, int))
{
	t_move	move;

	move = get_best_move(*from, *to, comp);
	while (from->list->value != move.elem_value)
		rotate(from);
	while (to->list->value != move.target_value)
		rotate(to);
	push(from, to);
}
