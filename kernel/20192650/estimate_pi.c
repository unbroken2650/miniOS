#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 64
#define NUM_POINTS 500000000

int in_circle_points = 0;
pthread_mutex_t mutex;

void *estimate_pi()
{
    int cnt = 0;
    double x, y;

    unsigned int seed = time(NULL) + pthread_self();

    for (int i = 0; i < NUM_POINTS / NUM_THREADS; i++)
    {
        x = (double)rand_r(&seed) / RAND_MAX * 2 - 1;
        y = (double)rand_r(&seed) / RAND_MAX * 2 - 1;
        if (x * x + y * y <= 1)
        {
            cnt++;
        }
    }

    pthread_mutex_lock(&mutex);
    in_circle_points += cnt;
    pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}

int week7()
{
    pthread_t thread_addrs[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&thread_addrs[i], NULL, estimate_pi, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(thread_addrs[i], NULL);
    }

    double pi_estimate = 4.0 * in_circle_points / NUM_POINTS;
    printf("Estimated Value of pi is %.10f\n", pi_estimate);

    in_circle_points = 0;
    pthread_mutex_destroy(&mutex);

    return 0;
}