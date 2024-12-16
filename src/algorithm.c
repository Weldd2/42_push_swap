/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:13:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:14:37 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_findclosest_ctx(t_findclosest_ctx *ctx, t_list list,
		t_comp_type type)
{
	ctx->curr = list.list;
	ctx->i = 0;
	ctx->found = 0;
	if (type == COMP_SMALLER)
		ctx->closest = INT_MIN;
	else
		ctx->closest = INT_MAX;
}

static void	check_update_closest(t_findclosest_ctx *c, int value, t_comp_type t)
{
	int	is_smaller;
	int	is_bigger;

	is_smaller = (t == COMP_SMALLER && c->curr->value < value
			&& c->curr->value > c->closest);
	is_bigger = (t == COMP_BIGGER && c->curr->value > value
			&& c->curr->value < c->closest);
	if (is_smaller || is_bigger)
	{
		c->closest = c->curr->value;
		c->ci = c->i;
		c->found = 1;
	}
}

static int	final_closest_index(t_findclosest_ctx *c, t_list list, t_comp_type t)
{
	if (!c->found)
	{
		if (t == COMP_SMALLER)
			return (find_max_index(list.list));
		return (find_min_index(list.list));
	}
	return (c->ci);
}

int	find_closest_index(int value, t_list list, t_comp_type type)
{
	t_findclosest_ctx	c;

	init_findclosest_ctx(&c, list, type);
	while (c.curr)
	{
		check_update_closest(&c, value, type);
		c.curr = c.curr->next;
		c.i++;
	}
	return (final_closest_index(&c, list, type));
}

static int	get_rot_case_costs(t_rot_costs co, int *li, t_rot_case *c)
{
	int	ca;
	int	cb;
	int	cc;
	int	cd;

	ca = max(co.e_upcost, co.t_upcost);
	cb = max(co.e_downcost, co.t_downcost);
	cc = co.e_upcost + co.t_downcost;
	cd = co.e_downcost + co.t_upcost;
	*li = ca;
	*c = BOTH_UP;
	if (cb < *li)
	{
		*li = cb;
		*c = BOTH_DOWN;
	}
	if (cc < *li)
	{
		*li = cc;
		*c = FROM_UP_TO_DOWN;
	}
	if (cd < *li)
	{
		*li = cd;
		*c = FROM_DOWN_TO_UP;
	}
	return (*li);
}

t_rot_case	determine_rot_case(t_rot_costs costs, int *local_min)
{
	t_rot_case	c;

	get_rot_case_costs(costs, local_min, &c);
	return (c);
}

bool	update_best_move(t_move *best, int *min_cost, int local_min, t_rot_costs co)
{
	if (local_min < *min_cost)
	{
		*min_cost = local_min;
		best->costs = co;
		return (true);
	}
	return (false);
}

static void	init_best_move_ctx(t_best_move_ctx *ctx, t_list from)
{
	ctx->cur = from.list;
	ctx->i = 0;
	ctx->minc = INT_MAX;
}

static void	check_lists_for_error(t_list from, t_list target)
{
	if (target.length == 0 || from.length == 0)
		ft_error();
}

static void	fill_costs(t_best_move_ctx *ctx, t_list from,
		t_list target, int ti)
{
	ctx->co.e_upcost = ctx->i;
	ctx->co.e_downcost = from.length - ctx->i;
	ctx->co.t_upcost = ti;
	ctx->co.t_downcost = target.length - ti;
}

static void	update_best_if_needed(t_best_move_ctx *ctx,
		t_list target, int ti, int value)
{
	if (update_best_move(&ctx->best, &ctx->minc, ctx->li, ctx->co))
	{
		ctx->best.elem_index = ctx->i;
		ctx->best.elem_value = value;
		ctx->best.target_index = ti;
		ctx->best.target_value = get_elem_by_index(target, ti);
		ctx->best.c = ctx->c;
	}
}

t_move	get_best_move(t_list from, t_list target, t_comp_type type)
{
	t_best_move_ctx	ctx;
	int				ti;

	check_lists_for_error(from, target);
	init_best_move_ctx(&ctx, from);
	while (ctx.cur)
	{
		ti = find_closest_index(ctx.cur->value, target, type);
		fill_costs(&ctx, from, target, ti);
		ctx.c = determine_rot_case(ctx.co, &ctx.li);
		update_best_if_needed(&ctx, target, ti, ctx.cur->value);
		ctx.i++;
		ctx.cur = ctx.cur->next;
	}
	return (ctx.best);
}

void	turk_algorithm(t_list *list_a, t_list *list_b)
{
	if (is_sorted(*list_a, ascending))
		return ;
	while (list_b->length != 2 && list_a->length != 3)
		push(list_a, list_b);
	while (list_a->length > 3)
		sort(list_a, list_b, COMP_SMALLER);
	sort_3(list_a);
	while (list_b->length > 0)
		sort(list_b, list_a, COMP_BIGGER);
}
