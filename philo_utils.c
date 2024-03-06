/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:03:09 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:42:00 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	error_msg(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error. ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}

// to print some msg you need resourse "to_show" If some thread already
// trying to print some msg, it will wait patiently
void	print_msg(t_philo *philo, char *msg)
{
	size_t	t;

	t = cur_time() - philo->tab->t_0;
	pthread_mutex_lock(&philo->tab->to_show);
	if (!philo->tab->philo_rip && !philo->tab->well_feed)
	{
		printf("%ld", t);
		printf(" %d ", philo->id);
		printf("%s", msg);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->tab->to_show);
}

size_t	cur_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
