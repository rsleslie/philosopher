#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philosopher;

	data = NULL;
	philosopher = NULL;
	if (check_args(argc, argv) != 0)
		return (1);
	if (init_values(argc, argv, data, philosopher) != 0)
		return (1);
	return (0);
}
