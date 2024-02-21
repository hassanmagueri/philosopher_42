#include "philo.h"
#include <string.h>

void *ft_philo(void *args)
{
    static int philo_id;

    
    printf("philo ra9am %d \n", ++philo_id);
    return NULL;
}

// todo ana philo

int main(int argc, char const *argv[])
{
    int num_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_meals;
    pthread_t *ths_ph;

    num_philo = atoi(argv[1]);
    ths_ph = malloc(sizeof(int) * num_philo);
    printf("num philo %d\n", num_philo);
    int i = 0;
    while (i < num_philo)
        pthread_create(&ths_ph[i++], NULL, &ft_philo, NULL);
    i = 0;
    while (i < num_philo)
        pthread_join(ths_ph[i], NULL);
    free(ths_ph);
    return 0;
}
