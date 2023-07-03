/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:56:23 by rleslie-          #+#    #+#             */
/*   Updated: 2023/07/02 20:40:21 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (write(2, " too few arguments. \n", 22));
	if (argc > 6)
		return (write(2, " too many arguments. \n", 22));
	if (ft_atol(argv[1]) == 0)
		return (write(2, " invalid number of philosophers. \n", 34));
	i = 1;
	while (argv[i])
	{
		if (ft_isnum(argv[i]) == 0)
			return (write(2, " invalid caracter. \n", 21));
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < 0)
			return (write(2, " invalid arguments. \n", 22));
		i++;
	}
	return (0);
}
