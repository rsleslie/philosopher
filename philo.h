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
	int				n_philosopher;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				n_must_eat;
	int				N_MUTEX;	           
	unsigned long	t_begin;
	pthread_mutex_t	*mutex;
}   t_data;

typedef struct s_philo
{
	int				id;
	int             lfork;
	int             rfork;
	long			last_meals;
	int             meal_counter;
	t_data          *data;
	pthread_mutex_t *fork;
} t_philo;

int		ft_isdigit(int c);
int		ft_isnum(char *str);
long	ft_atol(char const *str);
void    ft_free(t_data *data, t_philo *philo, pthread_t *th);
int		check_args(int argc, char **argv);
int 	init_data(int ac, char **argv, t_data *data);
int		init_mutex(t_data *data);
int		init_values(int ac, char **av, t_data *data, t_philo *philosopher);
int		init_threads(t_data *data, t_philo *philo);
int		observer(t_philo *philo, t_data *data);
int		time_begin(struct timeval start);

#endif
