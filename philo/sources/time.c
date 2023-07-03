/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:55:15 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 17:55:37 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	time_begin(void)
{
	struct timeval	end;
	long			miliseconds;

	gettimeofday(&end, NULL);
	miliseconds = (end.tv_sec * 1000) + (end.tv_usec / 1000);
	return (miliseconds);
}
