/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:45:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 20:44:29 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[3]);
	philo->last_meals = time_begin();
	pthread_mutex_unlock(&philo->data->mutex[3]);
	pthread_mutex_lock(&philo->data->mutex[2]);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->data->mutex[2]);
	ft_print(philo, "is eating");
	usleep(philo->data->t_eat * 1000);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	usleep(philo->data->t_slp * 1000);
	return (0);
}

int	ft_check(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->meal_counter == philo->data->n_must_eat)
		return (1);
	return (0);
}

int	get_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->fork[philo->lfork]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork[philo->rfork]);
		ft_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->fork[philo->rfork]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork[philo->lfork]);
		ft_print(philo, "has taken a fork");
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (philo->data->n_philosopher == 1)
		return (1);
	get_fork(philo);
	if (check_status(philo) != 0)
	{
		pthread_mutex_unlock(&philo->fork[philo->lfork]);
		pthread_mutex_unlock(&philo->fork[philo->rfork]);
		return (1);
	}
	eating(philo);
	pthread_mutex_unlock(&philo->fork[philo->lfork]);
	pthread_mutex_unlock(&philo->fork[philo->rfork]);
	if (check_status(philo) != 0)
		return (1);
	return (0);
}
