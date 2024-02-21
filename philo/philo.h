#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct s_philo
{
	int		id;
	
	char*	state;
} t_philo;
typedef struct s_monitor
{
	pthread_mutex_t mutex_pid;
} t_monitor;
