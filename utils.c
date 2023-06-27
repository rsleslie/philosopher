#include "philo.h"

long	ft_atol(char const *str)
{
	long	sign;
	long	nb;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			return (0);
		if (ft_isdigit(str[i]) != 0)
			return (0);
	}
	return (1);
}

void    ft_free(t_data *data, t_philo *philo, pthread_t *th)
{
	if (data && data->mutex)
		free (data->mutex);
	if (philo && philo->fork)
		free (philo->fork);
	if (th != NULL)
		free(th);
}
