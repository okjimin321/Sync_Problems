#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

void* writer(void* arg);
void* reader(void* arg);
int shared;
int readerCount = 0;

sem_t m, wSem;
sem_t x;

int main(){
    pthread_t t1, t2, t3;
    sem_init(&m, 0, 1);//for mutal exclusion x
    sem_init(&wSem, 0 , 1);//for Consumer 
    sem_init(&x, 0, 1);//for mutal exclusion readerCount

    pthread_create(&t1, NULL, writer, NULL);//writer 1
    pthread_create(&t2, NULL, reader, NULL);//reader 1
    pthread_create(&t3, NULL, reader, NULL);//reader 2

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void* writer(void* arg){
    int i, val;
    while(1){

        sem_wait(&wSem);
        sem_wait(&m);
        //critical section
        val = shared;//critical resource
        val = val + 1;
        printf("writer(%u): %d\n", (unsigned int) pthread_self(),  val);
        shared = val;
        sem_post(&m);
        sem_post(&wSem);
    }
    return NULL;
}

void* reader(void* arg){
    int i, val;
    while(1){
        sem_wait(&x);
        readerCount++;
        if(readerCount == 1){
            sem_wait(&wSem);
        }
        sem_post(&x);

        sem_wait(&m);
        //critical section
        val = shared;//critical resource
        printf("Reader(%u): %d\n", (unsigned int) pthread_self(),  val);
        sem_post(&m);

        sem_wait(&x);
        readerCount--;
        if(readerCount == 0){
            sem_post(&wSem);
        }
        sem_post(&x);
    }
    return NULL;
}
