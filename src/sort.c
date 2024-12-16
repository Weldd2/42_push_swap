/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:16:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:56:50 by antoinemura      ###   ########.fr       */
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

static void	rotate_both_up(t_list *from, t_list *to, int e_up_cost, \
		int t_up_cost)
{
	int	min_val;
	int	i;

	min_val = min(e_up_cost, t_up_cost);
	i = 0;
	while (i < min_val)
	{
		rotate_ab(from, to);
		i++;
	}
	i = min_val;
	while (i < e_up_cost)
	{
		rotate(from);
		i++;
	}
	i = min_val;
	while (i < t_up_cost)
	{
		rotate(to);
		i++;
	}
}

static void	rotate_both_down(t_list *from, t_list *to, int e_down_cost, \
		int t_down_cost)
{
	int	common;
	int	i;

	common = min(e_down_cost, t_down_cost);
	i = 0;
	while (i < common)
	{
		rrotate_ab(from, to);
		i++;
	}
	while (i < e_down_cost)
	{
		rrotate(from);
		i++;
	}
	i = common;
	while (i < t_down_cost)
	{
		rrotate(to);
		i++;
	}
}

static void	opposite_rotations_elem_up_target_down(t_list *from, \
	int elem_cost, t_list *to, int target_cost)
{
	int	i;

	i = 0;
	while (i < elem_cost)
	{
		rotate(from);
		i++;
	}
	i = 0;
	while (i < target_cost)
	{
		rrotate(to);
		i++;
	}
}

static void	opposite_rotations_elem_down_target_up(t_list *from, \
		int elem_cost, t_list *to, int target_cost)
{
	int	i;

	i = 0;
	while (i < elem_cost)
	{
		rrotate(from);
		i++;
	}
	i = 0;
	while (i < target_cost)
	{
		rotate(to);
		i++;
	}
}

void	apply_rotation_case(t_list *from, t_list *to, t_rotation_costs costs, \
			t_rotation_case rotation_case)
{
	if (rotation_case == BOTH_UP)
		rotate_both_up(from, to, costs.e_up_cost, costs.t_up_cost);
	else if (rotation_case == BOTH_DOWN)
		rotate_both_down(from, to, costs.e_down_cost, costs.t_down_cost);
	else if (rotation_case == FROM_UP_TO_DOWN)
		opposite_rotations_elem_up_target_down(from, \
			costs.e_up_cost, to, costs.t_down_cost);
	else if (rotation_case == FROM_DOWN_TO_UP)
		opposite_rotations_elem_down_target_up(from, \
		costs.e_down_cost, to, costs.t_up_cost);
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
