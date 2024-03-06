/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02arg_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:41:29 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:41:47 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi_safe(const char *str)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (str[i++] - '0') + (result * 10);
	if (i > 12 || result > 2147483647)
		error_msg(ERR_LARGE_ARG);
	return (result);
}

void	arg_init(char **av, t_table *tab)
{
	tab->num_philo = ft_atoi_safe(av[1]);
	tab->ms_to_die = ft_atoi_safe(av[2]);
	tab->ms_to_eat = ft_atoi_safe(av[3]);
	tab->ms_to_slp = ft_atoi_safe(av[4]);
	tab->maxnofmls = -1;
	if (av[5])
		tab->maxnofmls = ft_atoi_safe(av[5]);
	tab->philo_rip = 0;
	tab->well_feed = 0;
}
