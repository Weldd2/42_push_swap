/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:15:26 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 01:51:47 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PUSH_SWAP_H
# define TEST_PUSH_SWAP_H

# include "push_swap.h"
# include <assert.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

void	assertLinkedList(t_node *list, int *values, int length);

void	test_init();
void	test_swap();
void	test_push();
void	test_rotate();
void	test_rrotate();
void	test_closest();
void	test_get_best_move();
void	test_is_sorted();
void	test_is_reverse_sorted();
void	test_sort();

#endif