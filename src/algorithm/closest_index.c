/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:39:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 20:05:51 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	final_closest_index(
	t_find_closest_context *c, t_list list, t_comparison_type t)
{
	if (!c->found)
	{
		if (t == COMPARE_SMALLEST)
			return (find_max_index(list.head));
		return (find_min_index(list.head));
	}
	return (c->closest_index);
}

static void	check_update_closest(
	t_find_closest_context *c, int value, t_comparison_type t)
{
	int	is_smaller;
	int	is_bigger;

	is_smaller = (t == COMPARE_SMALLEST && c->current_node->value < value
			&& c->current_node->value > c->closest_value);
	is_bigger = (t == COMPARE_LARGEST && c->current_node->value > value
			&& c->current_node->value < c->closest_value);
	if (is_smaller || is_bigger)
	{
		c->closest_value = c->current_node->value;
		c->closest_index = c->index;
		c->found = 1;
	}
}

static void	init_findclosest_ctx(
	t_find_closest_context *ctx, t_list list, t_comparison_type type)
{
	ctx->current_node = list.head;
	ctx->index = 0;
	ctx->found = 0;
	if (type == COMPARE_SMALLEST)
		ctx->closest_value = INT_MIN;
	else
		ctx->closest_value = INT_MAX;
}

int	find_closest_index(int value, t_list list, t_comparison_type type)
{
	t_find_closest_context	c;

	init_findclosest_ctx(&c, list, type);
	while (c.current_node)
	{
		check_update_closest(&c, value, type);
		c.current_node = c.current_node->next;
		c.index++;
	}
	return (final_closest_index(&c, list, type));
}
