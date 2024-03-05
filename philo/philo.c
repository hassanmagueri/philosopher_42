#include "philo.h"
#include <string.h>

void    philo_init(t_philo *philo, int id)
{
	philo->id = id;
	philo->l_fork = 1;
	philo->r_fork = 1;
	philo->state = "";
}

void    monitor_init(t_monitor *monitor, int argc, char const *argv[])
{
	int i;

	i = 0;
	monitor->num_philo = ft_atoi(argv[1]);
	// monitor->time_to_die = ft_atoi(argv[2]);
	// monitor->time_to_eat = ft_atoi(argv[3]);
	// monitor->time_to_sleep = ft_atoi(argv[4]);
	// monitor->num_of_meals = -1;
	// if (argc == 6)
	// 	monitor->num_of_meals = ft_atoi(argv[5]);
	monitor->philos = malloc(sizeof(t_philo) * monitor->num_philo);
	while (i < monitor->num_philo)
	{
		philo_init(&(monitor->philos[i]), i + 1);
		i++;
	}
}

void	*ft_philo(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (1)
	{
		if(philo->l_fork && philo->r_fork)
		{
			printf("%d has taken a fork\n", philo->id);
			philo->l_fork = 0;
			philo->r_fork = 0;
			sleep(1);
		}
	}
	return NULL;
}

void    *ft_monitor(void *args)
{
	t_monitor	*moni;
	t_philo		*philo;
	int			i;

	i = 0;
	moni = (t_monitor *)args;
	while (i < moni->num_philo)
	{
		philo = &moni->philos[i];
		// printf("pid %d | next %d\n", philo->id, (philo->id + 1) % moni->num_philo);
		if (moni->philos[(i + 4) % moni->num_philo].r_fork == 1 && moni->philos[(i + 1) % moni->num_philo].l_fork == 1)
		{
			philo->l_fork = 1;
			philo->r_fork = 1;
		}
		pthread_create(&philo->thread_id, NULL, &ft_philo, philo);
		i++;
	}
	// while (1)
	// {
	// 	i = 0;
	// 	while (i < moni->num_philo)
	// 	{
	// 		philo = &moni->philos[i];
	// 		// if (moni->philos[(i - 1) % moni->num_philo].l_fork == 1 && moni->philos[(i + 1) % moni->num_philo].r_fork == 1)
	// 		if (moni->philos[(philo->id - 1) % moni->num_philo].l_fork == 1 && moni->philos[(philo->id + 1) % moni->num_philo].r_fork == 1)
	// 		{
	// 			philo->l_fork = 1;
	// 			philo->r_fork = 1;
	// 		}
	// 		sleep(1);
	// 		i++;
	// 	}
	// }
	i = 0;
	while (i < moni->num_philo)
	{
		philo = &moni->philos[i];
		pthread_join(philo->thread_id, NULL);
		i++;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t *ths_ph;
	t_philo	*philos;
	t_monitor monitor;
	int i;

	monitor_init(&monitor, argc, argv);
	pthread_create(&(monitor.thread_id), NULL, &ft_monitor, &monitor);
	pthread_join(monitor.thread_id, NULL);
	// ths_ph = malloc(sizeof(int) * num_philo);
	// philos = malloc(sizeof(int) * num_philo);
	// printf("num philo %d\n", num_philo);
	// i = 0;
	// while (i < num_philo)
	// {
	//     philos[i].id =  i;
	//     pthread_create(&ths_ph[i++], NULL, &ft_philo, NULL);
	// }
	// i = 0;
	// while (i < num_philo)
	//     pthread_join(ths_ph[i++], NULL);
	// free(monitor.philos);
	return 0;
}
