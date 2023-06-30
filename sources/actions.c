/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:45:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/06/30 14:35:20 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data.mutex[1]);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->data.mutex[1]);
	ft_print(philo, "has taken a fork");	
	ft_print(philo,"is eating");
	usleep(philo->data.t_eat * 1000);
	pthread_mutex_lock(&philo->data.mutex[3]);
	philo->last_meals = time_begin(philo->data.start);
	pthread_mutex_unlock(&philo->data.mutex[3]);
	return (0);
}

int	ft_sleep(t_philo philo)
{
	pthread_mutex_lock(&philo.data.mutex[4]);
	ft_print(&philo, "is sleeping");
	usleep(philo.data.t_slp * 1000);
	pthread_mutex_unlock(&philo.data.mutex[4]);
	return (0);
}

int	ft_check(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->data.mutex[2]);
	if (philo->meal_counter == philo->data.n_must_eat)
	{
		pthread_mutex_unlock(&philo->data.mutex[2]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data.mutex[2]);
	return (0);
}

int eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork[philo->lfork]);
		pthread_mutex_lock(&philo->fork[philo->rfork]);
	}
	else
	{
		pthread_mutex_lock(&philo->fork[philo->rfork]);
		pthread_mutex_lock(&philo->fork[philo->lfork]);
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
