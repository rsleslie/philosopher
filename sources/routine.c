#include "../includes/philo.h"

// 0123
//mutex 0  ->print
//mutex 1  -> meal_counter
//mutex 2  -> philo.meal_counter == philo.data.n_must_eat
//mutex 2  ->
//mutex 4  ->

void	ft_print(t_philo *philo, char *s)
{
	int status;

	pthread_mutex_lock(&philo->data->mutex[4]);
	status = philo[0].data->status;
	pthread_mutex_unlock(&philo->data->mutex[4]);
	if (status != 0)
	{
		pthread_mutex_lock(&philo->data->mutex[0]);
		printf("%lu\tPhilosopher\t%i\t%s.\n", (philo->t_begin - time_begin(philo->start)), philo->id, s);
		pthread_mutex_unlock(&philo->data->mutex[0]);
	}
}

int	observer(t_philo *philo)
{
	int	died;
	int	status;

	pthread_mutex_lock(&philo->data->mutex[5]);
	pthread_mutex_lock(&philo->data->mutex[6]);
	died = philo->last_meals - time_begin(philo->start);
	pthread_mutex_unlock(&philo->data->mutex[6]);
	if (died >= philo->data->t_die)
	{
		ft_print(philo, "died");
		pthread_mutex_lock(&philo->data->mutex[4]);
		philo[0].data->status = 0;
		pthread_mutex_unlock(&philo->data->mutex[4]);
		pthread_mutex_unlock(&philo->data->mutex[5]);
		return (1);
	}
	pthread_mutex_lock(&philo->data->mutex[4]);
	status = philo[0].data->status = 0;
	pthread_mutex_unlock(&philo->data->mutex[4]);
	if (status == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex[5]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex[5]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *)arg;
	gettimeofday(&philo->start, NULL);
	philo->t_begin = time_begin(philo->start);
	ft_print(philo, "thinking");
	while (1)
	{
		if (observer(philo) != 0 || (eat(philo) != 0) || (ft_check(philo) != 0) ||  (ft_sleep(philo) != 0))
			break ;
		ft_print(philo, "thinking");
	}
	return (NULL);
}
