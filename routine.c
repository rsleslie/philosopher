#include "philo.h"

//mutex 0 ->observer
int	observer(t_philo *philo, t_data *data)
{
	int i;
	int counter;
	int counter_meals;

	i = 0;
	counter = 0;
	counter_meals = 0;
	if (data->n_must_eat == -1)
		return (0);
	while (1)
	{
		if (i == data->n_philosopher)
		{
			if (counter_meals == data->n_philosopher - 1)
				return (1);
			i = 0;
			counter = 0;
		}
		pthread_mutex_lock(&data->mutex[0]);
		counter_meals = philo[i].meal_counter;
		pthread_mutex_unlock(&data->mutex[0]);
		if (counter_meals == data->n_must_eat)
			counter++;
		i++;
	}
	return (0);
}

void	ft_print(t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->data->mutex[1]);
	printf("%i\t");
	pthread_mutex_lock(philo->data->mutex[1]);
}

void	*routine(void *arg)
{
	t_philo philo;
	unsigned long time;

	philo = (void *)arg;
	gettimeofday(&philo->data->start, NULL);
	philo->data->t_begin = time_act(philo->data->start);
	while (1)
	{
		
	}
	
}