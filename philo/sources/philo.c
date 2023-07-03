/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:54:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 17:54:57 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philosopher;

	data = NULL;
	philosopher = NULL;
	if (check_args(argc, argv) != 0)
		return (1);
	if (init_values(argc, argv, data, philosopher) != 0)
		return (1);
	return (0);
}
