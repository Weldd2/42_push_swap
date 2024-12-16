/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:57:16 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 19:57:24 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	update_best_move(
	t_move *best, int *min_cost, int local_min, t_rotation_costs co)
{
	if (local_min < *min_cost)
	{
		*min_cost = local_min;
		best->costs = co;
		return (true);
	}
	return (false);
}
