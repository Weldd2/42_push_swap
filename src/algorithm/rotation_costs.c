/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_costs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:40:52 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 19:59:01 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_min_rotation_cost(t_rotation_costs co)
{
	int	ca;
	int	cb;
	int	cc;
	int	cd;
	int	min_cost;

	ca = max(co.e_up_cost, co.t_up_cost);
	cb = max(co.e_down_cost, co.t_down_cost);
	cc = co.e_up_cost + co.t_down_cost;
	cd = co.e_down_cost + co.t_up_cost;
	min_cost = ca;
	if (cb < min_cost)
		min_cost = cb;
	if (cc < min_cost)
		min_cost = cc;
	if (cd < min_cost)
		min_cost = cd;
	return (min_cost);
}

static t_rotation_case	determine_rotation_case(
	t_rotation_costs co, int min_cost)
{
	if (min_cost == max(co.e_up_cost, co.t_up_cost))
		return (BOTH_UP);
	if (min_cost == max(co.e_down_cost, co.t_down_cost))
		return (BOTH_DOWN);
	if (min_cost == (co.e_up_cost + co.t_down_cost))
		return (FROM_UP_TO_DOWN);
	if (min_cost == (co.e_down_cost + co.t_up_cost))
		return (FROM_DOWN_TO_UP);
	return (BOTH_UP);
}

static int	get_rotation_case_costs(
	t_rotation_costs co, int *li, t_rotation_case *rotation_case)
{
	*li = calculate_min_rotation_cost(co);
	*rotation_case = determine_rotation_case(co, *li);
	return (*li);
}

t_rotation_case	determine_rot_case(t_rotation_costs costs, int *local_min)
{
	t_rotation_case	rotation_case;

	get_rotation_case_costs(costs, local_min, &rotation_case);
	return (rotation_case);
}
