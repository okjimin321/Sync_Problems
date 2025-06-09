#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define ITER 1000
#define MAX 30

void* producer(void* arg);
void* consumer(void* arg);
int x;

sem_t m, fill, empty;
int main(){
    pthread_t t1, t2;
    sem_init(&m, 0, 1);//for mutal exclusion
    sem_init(&fill, 0 , 0);//for Consumer 

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    if(x != 0){
        printf("BOOOOM!!!\n");
    }
    else{
        printf("OK COMPUTER\n");
    }
}

void* producer(void* arg){
    int i, val;
    for(i = 0; i < ITER; i++){
        sem_wait(&m);
        //critical section
        val = x;//critical resource
        val = val + 1;
        printf("producer(%u): %d\n", (unsigned int) pthread_self(),  val);
        x = val;
        sem_post(&m);
        sem_post(&fill);
    }
    return NULL;
}

void* consumer(void* arg){
    int i, val;
    for(i = 0; i < ITER; i++){
        sem_wait(&fill);
        sem_wait(&m);
        //critical section
        val = x;
        val = val - 1;
        printf("consumer(%u): %d\n", (unsigned int) pthread_self(),  val);
        x = val;
        sem_post(&m);
    }
    return NULL;
}
