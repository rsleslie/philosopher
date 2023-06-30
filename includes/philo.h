#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				N_MUTEX;
	int				n_must_eat;
	int				n_philosopher;
	int				status;
	struct timeval	start;
	unsigned long	t_begin;
	pthread_t		*list_th;
	pthread_mutex_t	*mutex;
}   t_data;

typedef struct s_philo
{
	int				id;
	int             lfork;
	int             rfork;
	long			last_meals;
	int             meal_counter;
	int             status;
	t_data          data;
	pthread_mutex_t *fork;
} t_philo;

typedef struct s_observer
{
	t_philo			*philo;
	t_data          *data;
} t_observer;

int		ft_isdigit(int c);
int		ft_isnum(char *str);
long	ft_atol(char const *str);
void    ft_free(t_data *data, t_philo *philo, pthread_t *th);
int		check_args(int argc, char **argv);
int 	init_data(int ac, char **argv, t_data *data);
int		init_mutex(t_data *data);
int		init_values(int ac, char **av, t_data *data, t_philo *philosopher);
int		init_threads(t_data *data, t_philo *philo);
int		time_begin(struct timeval start);
void	*routine(void *arg);
int		eating(t_philo *philo);
void	ft_print(t_philo *philo, char *s);
int		observer(t_philo *philo, t_data *data);
int		ft_sleep(t_philo philo);
int		ft_check(t_philo *philo);
int		eat(t_philo *philo);

#endif
