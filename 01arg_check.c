/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01arg_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:38:16 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:41:37 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	arg_check(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5)
		error_msg(ERR_FEW_ARGS);
	if (ac > 6)
		error_msg(ERR_LOTS_ARGS);
	j = 0;
	while (av[0][j])
		j++;
	if (ft_strcmp("philo", &av[0][j - 5]))
		error_msg(ERR_NAME_PROG);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				error_msg(ERR_CHAR_ARGS);
			j++;
		}
		i++;
	}
}
