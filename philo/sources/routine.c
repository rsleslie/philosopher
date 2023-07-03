/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:00:37 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 21:05:19 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, char *s)
{
	int	status;

	pthread_mutex_lock(&philo->data->mutex[4]);
	status = philo[0].data->status;
	pthread_mutex_unlock(&philo->data->mutex[4]);
	if (status != 0)
	{
		pthread_mutex_lock(&philo->data->mutex[0]);
		printf("%lu\t%i\t%s\n", (time_begin() - philo->t_begin), philo->id, s);
		pthread_mutex_unlock(&philo->data->mutex[0]);
	}
}

int	is_died(t_philo *philo, int i)
{
	int	died;

	pthread_mutex_lock(&philo[i].data->mutex[3]);
	died = philo[i].last_meals;
	pthread_mutex_unlock(&philo[i].data->mutex[3]);
	if ((time_begin() - died) >= philo[0].data[0].t_die)
	{
		ft_print(&philo[i], "died");
		pthread_mutex_lock(&philo[i].data->mutex[4]);
		philo[0].data->status = 0;
		pthread_mutex_unlock(&philo[i].data->mutex[4]);
		return (1);
	}
	return (0);
}

int	must_eat(int counter, t_philo *philo, int i)
{
	int	meal_counter;

	pthread_mutex_lock(&philo[0].data->mutex[2]);
	meal_counter = philo[i].meal_counter;
	pthread_mutex_unlock(&philo[0].data->mutex[2]);
	if ((philo->data->n_must_eat != -1)
		&& (meal_counter >= philo[0].data->n_must_eat))
		counter++;
	if ((philo->data->n_must_eat != -1)
		&& (counter == philo[0].data->n_philosopher))
		return (-1);
	return (counter);
}

void	*observer(void *arg)
{
	int		i;
	int		counter;
	t_philo	*philo;

	i = 0;
	counter = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		i = i % philo[0].data->n_philosopher;
		if (is_died(philo, i) == 1)
			break ;
		counter = must_eat(counter, philo, i);
		if (counter == -1)
			break ;
		if (i == philo[0].data->n_philosopher - 1)
			counter = 0;
		i++;
		usleep(10000);
	}
	return (NULL);
}

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[4]);
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex[4]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex[4]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(30000);
	ft_print(philo, "is thinking");
	while (!check_status(philo))
	{
		if (check_status(philo) != 0)
			break ;
		if (eat(philo) != 0)
			break ;
		if (ft_check(philo) != 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		ft_print(philo, "is thinking");
		if (philo->id % 2 != 0)
			usleep(2000);
	}
	return (NULL);
}
