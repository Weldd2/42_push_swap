/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:13:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 20:13:39 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *list)
{
	int	first;
	int	second;
	int	third;

	first = list->head->value;
	second = list->head->next->value;
	third = list->head->next->next->value;
	if (list->length != 3)
		ft_error();
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

void	sort(t_list *from, t_list *to, t_comparison_type type)
{
	t_move				move;
	t_rotation_costs	costs;
	t_rotation_case		rotation_case;

	move = get_best_move(*from, *to, type);
	costs = move.costs;
	rotation_case = move.rotation_case;
	apply_rotation_case(from, to, costs, rotation_case);
	push(from, to);
}

void	turk_algorithm(t_list *list_a, t_list *list_b)
{
	if (is_sorted(*list_a, ascending))
		return ;
	while (list_b->length != 2 && list_a->length != 3)
		push(list_a, list_b);
	while (list_a->length > 3)
		sort(list_a, list_b, COMPARE_SMALLEST);
	sort_3(list_a);
	while (list_b->length > 0)
		sort(list_b, list_a, COMPARE_LARGEST);
}
