/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:45:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 13:07:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *nptr)
{
	int			signe;
	long long	total;

	signe = 1;
	total = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -signe;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		total = total * 10;
		total += (*nptr - '0');
		nptr++;
	}
	return (total * signe);
}
