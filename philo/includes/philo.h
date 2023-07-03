/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:49:34 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 19:45:51 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	long			t_die;
	int				t_eat;
	int				t_slp;
	int				n_mutex;
	int				n_must_eat;
	int				n_philosopher;
	int				status;
	void			*philo_data;
	pthread_mutex_t	*mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				lfork;
	int				rfork;
	long			last_meals;
	int				meal_counter;
	t_data			*data;
	unsigned long	t_begin;
	struct timeval	start;
	pthread_mutex_t	*fork;
}	t_philo;

int		ft_isdigit(int c);
int		ft_isnum(char *str);
long	ft_atol(char const *str);
void	ft_free(t_data *data, t_philo *philo, pthread_t *th);
int		check_args(int argc, char **argv);
int		init_data(int ac, char **argv, t_data *data);
int		init_mutex(t_data *data);
int		init_values(int ac, char **av, t_data *data, t_philo *philosopher);
int		init_threads(t_data *data, t_philo *philo);
int		time_begin(void);
void	*routine(void *arg);
int		eating(t_philo *philo);
void	ft_print(t_philo *philo, char *s);
void	*observer(void *arg);
int		ft_sleep(t_philo *philo);
int		ft_check(t_philo *philo);
int		eat(t_philo *philo);
int		check_status(t_philo *philo);

#endif
