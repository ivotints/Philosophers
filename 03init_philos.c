/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03init_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:48:21 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:43:06 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_table *tab)
{
	int	i;

	tab->philos = (t_philo *)malloc(tab->num_philo * sizeof(t_philo));
	if (!tab->philos)
		error_msg(ERR_MALLOC);
	i = -1;
	while (++i < tab->num_philo)
	{
		tab->philos[i].id = i + 1;
		tab->philos[i].tab = tab;
		tab->philos[i].eat_num = 0;
		if (i + 1 == tab->num_philo)
			tab->philos[i].next = & tab->philos[0];
		else
			tab->philos[i].next = &tab->philos[i + 1];
		if (i == 0)
			tab->philos[i].previous = &tab->philos[tab->num_philo - 1];
		else
			tab->philos[i].previous = &tab->philos[i - 1];
		pthread_mutex_init(&tab->philos[i].fork, NULL);
	}
	pthread_mutex_init(&tab->to_show, NULL);
	pthread_mutex_init(&tab->to_check, NULL);
}
