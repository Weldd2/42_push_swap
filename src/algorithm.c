/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:13:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 14:04:02 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_findclosest_ctx(t_find_closest_context *ctx, t_list list, \
		t_comparison_type type)
{
	ctx->current_node = list.head;
	ctx->index = 0;
	ctx->found = 0;
	if (type == COMPARE_SMALLEST)
		ctx->closest_value = INT_MIN;
	else
		ctx->closest_value = INT_MAX;
}

static void	check_update_closest(t_find_closest_context *c, \
		int value, t_comparison_type t)
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

static int	final_closest_index(t_find_closest_context *c, t_list list, \
		t_comparison_type t)
{
	if (!c->found)
	{
		if (t == COMPARE_SMALLEST)
			return (find_max_index(list.head));
		return (find_min_index(list.head));
	}
	return (c->closest_index);
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

static int	get_rotation_case_costs(t_rotation_costs co, int *li, \
		t_rotation_case *rotation_case)
{
	int	ca;
	int	cb;
	int	cc;
	int	cd;

	ca = max(co.e_up_cost, co.t_up_cost);
	cb = max(co.e_down_cost, co.t_down_cost);
	cc = co.e_up_cost + co.t_down_cost;
	cd = co.e_down_cost + co.t_up_cost;
	*li = ca;
	*rotation_case = BOTH_UP;
	if (cb < *li)
	{
		*li = cb;
		*rotation_case = BOTH_DOWN;
	}
	if (cc < *li)
	{
		*li = cc;
		*rotation_case = FROM_UP_TO_DOWN;
	}
	if (cd < *li)
	{
		*li = cd;
		*rotation_case = FROM_DOWN_TO_UP;
	}
	return (*li);
}

t_rotation_case	determine_rot_case(t_rotation_costs costs, int *local_min)
{
	t_rotation_case	rotation_case;

	get_rotation_case_costs(costs, local_min, &rotation_case);
	return (rotation_case);
}

bool	update_best_move(t_move *best, int *min_cost, int local_min, \
	t_rotation_costs co)
{
	if (local_min < *min_cost)
	{
		*min_cost = local_min;
		best->costs = co;
		return (true);
	}
	return (false);
}

static void	init_best_move_ctx(t_best_move_context *ctx, t_list from)
{
	ctx->current_node = from.head;
	ctx->index = 0;
	ctx->min_cost = INT_MAX;
}

static void	check_lists_for_error(t_list from, t_list target)
{
	if (target.length == 0 || from.length == 0)
		ft_error();
}

static void	fill_costs(t_best_move_context *ctx, t_list from,
		t_list target, int target_index)
{
	ctx->rotation_costs.e_up_cost = ctx->index;
	ctx->rotation_costs.e_down_cost = from.length - ctx->index;
	ctx->rotation_costs.t_up_cost = target_index;
	ctx->rotation_costs.t_down_cost = target.length - target_index;
}

static void	update_best_if_needed(t_best_move_context *ctx,
		t_list target, int target_index, int value)
{
	if (update_best_move(&ctx->best_move, &ctx->min_cost, \
		ctx->local_index, ctx->rotation_costs))
	{
		ctx->best_move.element_index = ctx->index;
		ctx->best_move.element_value = value;
		ctx->best_move.target_index = target_index;
		ctx->best_move.target_value = get_elem_by_index(target, target_index);
		ctx->best_move.rotation_case = ctx->rotation_case;
	}
}

t_move	get_best_move(t_list from, t_list target, t_comparison_type type)
{
	t_best_move_context	ctx;
	int					target_index;

	check_lists_for_error(from, target);
	init_best_move_ctx(&ctx, from);
	while (ctx.current_node)
	{
		target_index = find_closest_index(ctx.current_node->value, \
			target, type);
		fill_costs(&ctx, from, target, target_index);
		ctx.rotation_case = determine_rot_case(ctx.rotation_costs, \
			&ctx.local_index);
		update_best_if_needed(&ctx, target, target_index, \
			ctx.current_node->value);
		ctx.index++;
		ctx.current_node = ctx.current_node->next;
	}
	return (ctx.best_move);
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
