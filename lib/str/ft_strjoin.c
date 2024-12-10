/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:46:02 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 19:14:53 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char *ft_strvjoin(char *str, ...)
{
	va_list	ap;
	char	*r;
	char	*next_str;
	char	*temp;

	if (!str)
		return (NULL);
	r = (char *)malloc(sizeof(char));
	if (!r)
		return (NULL);
	r[0] = '\0';
	va_start(ap, str);
	next_str = str;
	while (next_str != NULL)
	{
		temp = r;
		r = ft_strjoin(r, next_str);
		free(temp);
		if (!r)
			return (va_end(ap), NULL);
		next_str = va_arg(ap, char *);
	}
	va_end(ap);
	return (r);
}
