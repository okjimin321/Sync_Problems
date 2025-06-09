#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define NUM 5

sem_t forks[NUM];
void pick_up(int p_num){
    sem_wait(&forks[p_num % NUM]);
    printf("philosopher %d picks fork %d \n", p_num, p_num % NUM);
}
void put_down(int p_num){
    sem_post(&forks[p_num % NUM]);
    printf("philosopher %d put down fork %d\n", p_num, p_num % NUM);
}
void thinking(int p_num){
    printf("philosopher %d is Thinking\n", p_num);
}
void eating(int p_num){
    printf("philosopher %d is Eating\n", p_num);
}

void* philosopher(void* arg){
    int p_num = (unsigned long int)arg;
    for(int i = 0; i < 10000; i++){
        //pick up the fork
        pick_up(p_num);
        pick_up(p_num + 1);

        eating(p_num);

        //put down fork
        put_down(p_num + 1);
        put_down(p_num);

        thinking(p_num);


    }
}

int main(){
    pthread_t threads[NUM];

    //initialize semaphore
    for(int i = 0; i < NUM; i++){
        sem_init(&forks[i], 0 , 1);
    }

    //make threads
    for(unsigned long int i = 0; i < NUM; i++){
        pthread_create(&threads[i], NULL, philosopher, (void*)i);
    }

    //join threads
    for(unsigned long int i = 0; i < NUM; i++){
        pthread_join(threads[i], NULL);
    }

    printf("NO DEADLOCK\n");
    return 0;

}