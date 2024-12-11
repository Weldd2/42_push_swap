/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:20:48 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 01:53:24 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int argc, __attribute__((unused)) char **argv)
{
	if (argc == 1)
		ft_error();
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv);
}
