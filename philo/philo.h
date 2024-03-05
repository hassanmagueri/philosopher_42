#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_philo
{
	int			id;
	int			l_fork;
	int			r_fork;
	char		*state;
	pthread_t	thread_id;
} t_philo;
typedef struct s_monitor
{
	pthread_t		thread_id;
	int 			num_philo;
    int 			time_to_die;
    int 			time_to_eat;
    int 			time_to_sleep;
    int 			num_of_meals;
	t_philo			*philos;
	pthread_mutex_t	mutex_pid;
	pthread_mutex_t	mutex_l_fork;
	pthread_mutex_t	mutex_r_fork;
} t_monitor;

int	ft_atoi(const char	*str);
