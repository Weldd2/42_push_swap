/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:20:48 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:22:01 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*args_to_values(char **args, int nb_args)
{
	int			*values;
	int			i;
	long long	value;

	values = malloc(sizeof(int) * (nb_args));
	i = 0;
	while (i < nb_args)
	{
		value = ft_atoi(args[i]);
		if (has_duplicate(values, i, (int)value) == true
			|| value > INT_MAX || value < INT_MIN)
			ft_error();
		values[i] = (int)value;
		i++;
	}
	return (values);
}

void	parse_args(int argc, char **argv, t_list *list_a, t_list *list_b)
{
	int			i;
	int			*values;
	char		**args;
	int			nb_args;

	i = 0;
	if (argc == 1)
		ft_error();
	args = argv + 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[i] != NULL)
			i++;
		nb_args = i;
	}
	if (argc > 2)
		nb_args = argc - 1;
	values = args_to_values(args, nb_args);
	init_t_lists(list_a, list_b, values, nb_args);
}

bool	has_duplicate(int *values, int nb_values, int value)
{
	int	i;

	i = 0;
	while (i < nb_values)
	{
		if (values[i] == value)
			return (true);
		i++;
	}
	return (false);
}
