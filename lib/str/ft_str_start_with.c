/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_start_with.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:19:32 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/12 15:08:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_str_start_with(char *string, char *test)
{
	int	test_l;
	int	i;
	int	valid;

	valid = 1;
	test_l = (int)ft_strlen(test);
	i = 0;
	while (i < test_l)
	{
		if (string[i] != test[i])
			valid = 0;
		i++;
	}
	return (valid);
}
