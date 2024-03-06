/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:26:11 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:41:56 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	the_exit(t_table *tab, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < tab->num_philo)
		pthread_join(id[i], NULL);
	i = -1;
	while (++i < tab->num_philo)
		pthread_mutex_destroy(&tab->philos[i].fork);
	pthread_mutex_destroy(&tab->to_show);
	pthread_mutex_destroy(&tab->to_check);
	free(tab->philos);
	free(id);
}

static void	ft_check_death(t_table *tab)
{
	int	i;

	while (!tab->well_feed)
	{
		i = -1;
		while (!tab->philo_rip && ++i < tab->num_philo)
		{
			pthread_mutex_lock(&tab->to_check);
			if (cur_time() - tab->philos[i].last_meal > (size_t)tab->ms_to_die)
			{
				print_msg(&tab->philos[i], MSG_DIED);
				tab->philo_rip = 1;
			}
			pthread_mutex_unlock(&tab->to_check);
			usleep(100);
		}
		if (tab->philo_rip)
			break ;
		i = 0;
		while (tab->maxnofmls != -1 && i < tab->num_philo
			&& tab->philos[i].eat_num >= tab->maxnofmls)
			i++;
		if (i == tab->num_philo)
			tab->well_feed = 1;
	}
}

int	main(int ac, char **av)
{
	t_table		tab;
	pthread_t	*id;

	arg_check(ac, av);
	arg_init(av, &tab);
	init_philos(&tab);
	id = (pthread_t *)malloc(tab.num_philo * sizeof(pthread_t));
	tab.t_0 = cur_time();
	init_thread(&tab, &id);
	ft_check_death(&tab);
	the_exit(&tab, id);
	return (0);
}
