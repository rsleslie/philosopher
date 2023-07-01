#include "../includes/philo.h"


int	init_threads(t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	*th;

	i = -1;
	th = malloc(sizeof(pthread_t) * data->n_philosopher);
	data->list_th = th;
	while (++i < data->n_philosopher)
	{
		if (pthread_create(&th[i], NULL, &routine, &philo[i]) != 0)
			return (1);
	}
	i = -1;
	while (++i < data->n_philosopher)
		pthread_join(th[i], NULL);
	return (0);
}

int	init_mutex(t_data *data)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = -1;
	mutex = malloc(sizeof(pthread_mutex_t) * data->N_MUTEX);
	if (mutex == NULL)
		return (1);
	while (++i < data->N_MUTEX)
		pthread_mutex_init(&mutex[i], NULL);
	data->mutex = mutex;
	return (0);
}

int init_data(int ac, char **argv, t_data *data)
{
	data->n_philosopher = ft_atol(argv[1]); 
	data->t_die = ft_atol(argv[2]);
	data->t_eat = ft_atol(argv[3]);
	data->t_slp = ft_atol(argv[4]);
	data->N_MUTEX = 13;
	data->status = 1;
	if (ac ==  5)
		data->n_must_eat = -1;
	else
		data->n_must_eat = ft_atol(argv[5]);
	
	if (init_mutex(data) == 1)
		return (1);
	return (0);
}

int	init_philosopher(t_data *data, t_philo *philosopher)
{
	int	i;
	pthread_mutex_t	*fork;

	i = -1;
	fork = malloc(sizeof(pthread_mutex_t) * data->n_philosopher);
	if (fork == NULL)
		return (1);
	while (++i < data->n_philosopher)
		pthread_mutex_init(&fork[i], NULL);
	i = -1;
	while (++i < data->n_philosopher)
	{
		philosopher[i].id = i + 1;
		philosopher[i].rfork = i;
		if (i - 1 < 0)
			philosopher[i].lfork = data->n_philosopher - 1;
		else
			philosopher[i].lfork = i - 1;
		philosopher[i].meal_counter = 0;
		philosopher[i].last_meals = 0;
		philosopher[i].data = data;
		philosopher[i].fork = fork;
		philosopher[i].status = 0;
	}
	return (0);
}

int init_values(int ac, char **av, t_data *data, t_philo *philosopher)
{
	int i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (init_data(ac, av, data) != 0)
		return (1);
	philosopher = malloc(sizeof(t_philo) * data->n_philosopher);
	if (init_philosopher(data, philosopher) != 0)
		return (1);
	if (init_threads(data, philosopher) != 0)
		return (1);
	while (++i < data->N_MUTEX)
		pthread_mutex_destroy(&data->mutex[i]);
	while (++i < data->n_philosopher)
		pthread_mutex_destroy(&philosopher->fork[i]);
	return (0);
}
