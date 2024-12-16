/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:16:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:15:58 by antoinemura      ###   ########.fr       */
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

static void	rotate_both_up(t_list *from, t_list *to, int e_upcost, int t_upcost)
{
	int	min_val;
	int	i;

	min_val = min(e_upcost, t_upcost);
	i = 0;
	while (i < min_val)
	{
		rotate_ab(from, to);
		i++;
	}
	i = min_val;
	while (i < e_upcost)
	{
		rotate(from);
		i++;
	}
	i = min_val;
	while (i < t_upcost)
	{
		rotate(to);
		i++;
	}
}

static void	rotate_both_down(t_list *from, t_list *to, int e_downcost, int t_downcost)
{
	int	common;
	int	i;

	common = min(e_downcost, t_downcost);
	i = 0;
	while (i < common)
	{
		rrotate_ab(from, to);
		i++;
	}
	while (i < e_downcost)
	{
		rrotate(from);
		i++;
	}
	i = common;
	while (i < t_downcost)
	{
		rrotate(to);
		i++;
	}
}

static void	opposite_rotations_elem_up_target_down(t_list *from, int elem_cost, t_list *to, int target_cost)
{
	int i;

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

static void	opposite_rotations_elem_down_target_up(t_list *from, int elem_cost, t_list *to, int target_cost)
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

void	apply_c(t_list *from, t_list *to, t_rot_costs costs, t_rot_case c)
{
	if (c == BOTH_UP)
		rotate_both_up(from, to, costs.e_upcost, costs.t_upcost);
	else if (c == BOTH_DOWN)
		rotate_both_down(from, to, costs.e_downcost, costs.t_downcost);
	else if (c == FROM_UP_TO_DOWN)
		opposite_rotations_elem_up_target_down(from, costs.e_upcost, to, costs.t_downcost);
	else if (c == FROM_DOWN_TO_UP)
		opposite_rotations_elem_down_target_up(from, costs.e_downcost, to, costs.t_upcost);
}

void	sort(t_list *from, t_list *to, t_comp_type type)
{
	t_move	move;
	t_rot_costs	costs;
	t_rot_case	c;

	move = get_best_move(*from, *to, type);
	costs = move.costs;
	c = move.c;
	apply_c(from, to, costs, c);
	push(from, to);
}
