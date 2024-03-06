/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04init_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:50:02 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:43:04 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait(t_table *tab, size_t ms)
{
	size_t	t;

	t = cur_time();
	while (!(tab->philo_rip))
	{
		if (cur_time() - t >= ms)
			break ;
		usleep(100);
	}
}

static void	eating(t_philo *philo, t_table *tab)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, MSG_FORK);
	if (tab->num_philo == 1)
	{
		wait(tab, tab->ms_to_die);
		print_msg(philo, MSG_DIED);
		pthread_mutex_unlock(&philo->fork);
		tab->philo_rip = 1;
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo, MSG_FORK);
	pthread_mutex_lock(&tab->to_check);
	philo->eat_num++;
	print_msg(philo, MSG_EATS);
	philo->last_meal = cur_time();
	pthread_mutex_unlock(&tab->to_check);
	wait(tab, tab->ms_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

// we need usleep to prevent taking only 1 forks by each philo
static void	*life(void *arg)
{
	t_philo	*philo;
	t_table	*tab;

	philo = (t_philo *)arg;
	tab = philo->tab;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!tab->philo_rip && !tab->well_feed)
	{
		eating(philo, philo->tab);
		print_msg(philo, MSG_SLEP);
		wait(tab, tab->ms_to_slp);
		print_msg(philo, MSG_THNK);
	}
	return (NULL);
}

void	init_thread(t_table *tab, pthread_t **id)
{
	int	i;

	i = -1;
	while (++i < tab->num_philo)
	{
		if (pthread_create(&id[0][i], NULL, &life, &tab->philos[i]))
		{
			free(tab->philos);
			free(*id);
			error_msg(ERR_THREAD);
		}
		pthread_mutex_lock(&(tab->to_check));
		tab->philos[i].last_meal = tab->t_0;
		pthread_mutex_unlock(&tab->to_check);
	}
}
