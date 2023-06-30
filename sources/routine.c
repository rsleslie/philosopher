#include "../includes/philo.h"

//mutex 0  ->print
//mutex 1  -> meal_counter
//mutex 2  -> philo.meal_counter == philo.data.n_must_eat
//mutex 2  ->
//mutex 4  ->


void	ft_print(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->data.mutex[0]);
	printf("%lu\tPhilosopher\t%i\t%s.\n", (philo->data.t_begin - time_begin(philo->data.start)), philo->id, s);
	pthread_mutex_unlock(&philo->data.mutex[0]);
}

int	observer(t_philo *philo, t_data *data)
{
	int	died;
	int	i;
	
	pthread_mutex_lock(&philo->data.mutex[7]);
	i = 0;
	if (data->status == 0)
	{
		pthread_mutex_unlock(&philo->data.mutex[7]);
		return (1);
	}
	while (i < philo->data.n_philosopher)
	{
		pthread_mutex_lock(&philo->data.mutex[6]);
		died = philo[i].last_meals - time_begin(philo->data.start);
		pthread_mutex_unlock(&philo->data.mutex[6]);
		if (died > philo[i].data.t_die)
		{
			ft_print(philo, "died");
			philo->data.status = 0;
			pthread_mutex_unlock(&philo->data.mutex[7]);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&philo->data.mutex[7]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *)arg;
	gettimeofday(&philo->data.start, NULL);
	philo->data.t_begin = time_begin(philo->data.start);
	ft_print(philo, "thinking");
	while (1)
	{
		// if (observer(philo, philo->data) != 0)
        //     break ;
		if ((eat(philo) != 0) || (ft_check(philo) != 0) || (ft_sleep(*philo) != 0))
			break ;
		ft_print(philo, "thinking");
	}
	return (NULL);
}
