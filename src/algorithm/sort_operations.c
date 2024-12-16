/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:39 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 20:06:28 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_up(t_list *from, t_list *to, int e_up_cost, \
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

void	rotate_both_down(t_list *from, t_list *to, int e_down_cost, \
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

void	opposite_rotations_elem_up_target_down(t_list *from, \
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

void	opposite_rotations_elem_down_target_up(t_list *from, \
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
