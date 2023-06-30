#include "../includes/philo.h"

int	time_begin(struct timeval start)
{
	struct timeval	end;
	long			seconds;
	long			microseconds;
	long			miliseconds;

	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_usec;
	microseconds = end.tv_usec - start.tv_usec;
	miliseconds = (seconds * 1000) + (microseconds / 1000);
	return (miliseconds * (-1));
}
