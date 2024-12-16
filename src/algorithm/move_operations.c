/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:41:33 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 19:56:46 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	fill_costs(
	t_best_move_context *ctx, t_list from, t_list target, int target_index)
{
	ctx->rotation_costs.e_up_cost = ctx->index;
	ctx->rotation_costs.e_down_cost = from.length - ctx->index;
	ctx->rotation_costs.t_up_cost = target_index;
	ctx->rotation_costs.t_down_cost = target.length - target_index;
}

static void	update_best_if_needed(
	t_best_move_context *ctx, t_list target, int target_index, int value)
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
		target_index = find_closest_index(
				ctx.current_node->value, target, type);
		fill_costs(&ctx, from, target, target_index);
		ctx.rotation_case = determine_rot_case(
				ctx.rotation_costs, &ctx.local_index);
		update_best_if_needed(
			&ctx, target, target_index, ctx.current_node->value);
		ctx.index++;
		ctx.current_node = ctx.current_node->next;
	}
	return (ctx.best_move);
}
