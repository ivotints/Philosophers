/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:07:27 by ivotints          #+#    #+#             */
/*   Updated: 2024/03/02 19:14:52 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

//Colors
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"

//errors
# define ERR_FEW_ARGS "Small amount of arguments. Please indicate:\n\
NumOfPhilos TimeToDie TimeToEat TimeToSleep [NumOfMeals]"
# define ERR_LOTS_ARGS "Large amount of arguments. Please indicate:\n\
NumOfPhilos TimeToDie TimeToEat TimeToSleep [NumOfMeals]"
# define ERR_CHAR_ARGS "An unauthorized character was found in the arguments"
# define ERR_NAME_PROG "Wrong name og the program. Should be \"philo\""
# define ERR_LARGE_ARG "Too large argument. Can not be more than 2147483647"
# define ERR_MALLOC "Memory allocation failure"
# define ERR_THREAD "Failed to create thread"

//messages
# define MSG_FORK "has taken a fork"
# define MSG_EATS "is eating"
# define MSG_SLEP "is sleeping"
# define MSG_THNK "is thinking"
# define MSG_DIED "died"

typedef struct s_philo
{
	int				id;
	int				eat_num;
	size_t			last_meal;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*previous;
	struct s_table	*tab;
}	t_philo;

typedef struct s_table
{
	int				num_philo;
	int				ms_to_die;
	int				ms_to_eat;
	int				ms_to_slp;
	int				maxnofmls;
	size_t			t_0;
	t_philo			*philos;
	pthread_mutex_t	to_show;
	pthread_mutex_t	to_check;
	int				philo_rip;
	int				well_feed;
}				t_table;

//main
void	arg_check(int ac, char **av);
void	arg_init(char **av, t_table *tab);
void	init_philos(t_table *tab);
void	init_thread(t_table *tab, pthread_t **id);

//utils
size_t	cur_time(void);
void	print_msg(t_philo *philo, char *msg);
int		error_msg(char *str);

#endif
