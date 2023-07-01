/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:45:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/01 16:13:56 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
//5 - 7- 8 - 9 - 10 - 11 - 12 --13
int	eating(t_philo *philo)
{
	if (observer(philo) != 0)
		return (1);
	
	philo->meal_counter++;
	philo->last_meals = time_begin(philo->start);
	ft_print(philo,"is eating");
	usleep(philo->data->t_eat * 1000);
	if (observer(philo) != 0)
		return (1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	// if (observer(philo) != 0)
	// 	return (1);
	ft_print(philo, "is sleeping");
	usleep(philo->data->t_slp * 1000);
	if (observer(philo) != 0)
		return (1);
	return (0);
}

int	ft_check(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->data->mutex[2]);
	if (philo->meal_counter == philo->data->n_must_eat)
	{
		pthread_mutex_unlock(&philo->data->mutex[2]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex[2]);
	return (0);
}

int eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
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
	if (eating(philo) == 1)
	{
		pthread_mutex_unlock(&philo->fork[philo->lfork]);
		pthread_mutex_unlock(&philo->fork[philo->rfork]);
		return (1);
	}	
	pthread_mutex_unlock(&philo->fork[philo->lfork]);
	pthread_mutex_unlock(&philo->fork[philo->rfork]);
	return (0);
}
