/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:27:52 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 20:04:21 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
