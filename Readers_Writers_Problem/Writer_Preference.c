#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

void* writer(void* arg);
void* reader(void* arg);
int shared = 0;
int readerCount = 0;
int writerCount = 0;

sem_t m, wSem, rSem;
sem_t x, y, z;

int main(){
    pthread_t t1, t2, t3;
    sem_init(&m, 0, 1);//mutal exclusion x
    sem_init(&wSem, 0 , 1);
    sem_init(&rSem, 0, 1);
    sem_init(&x, 0, 1);//mutal exclusion readerCount
    sem_init(&y, 0, 1);//mutal exclusion writeCount
    sem_init(&z, 0, 1);//for corner case

    pthread_create(&t1, NULL, writer, NULL);//writer 1
    pthread_create(&t2, NULL, reader, NULL);//reader 1
    pthread_create(&t3, NULL, reader, NULL);//reader 2

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void* writer(void* arg){
    int i, val;
    while(1){
        sem_wait(&y);
        writerCount++;
        if(writerCount == 1){
            sem_wait(&rSem);
        }
        sem_post(&y);

        sem_wait(&wSem);
        //critical section
        printf("writer(%u): %d\n", (unsigned int)pthread_self(), ++shared);
        sem_post(&wSem);

        sem_wait(&y);
        writerCount--;
        if(writerCount == 0){
            sem_post(&rSem);
        }
        sem_post(&y);
    }
    return NULL;
}

void* reader(void* arg){
    int i, val;
    while(1){
        sem_wait(&z);
        sem_wait(&rSem);
        sem_wait(&x);
        readerCount++;
        if(readerCount == 1){
            sem_wait(&wSem);
        }
        sem_post(&x);
        sem_post(&rSem);
        sem_post(&z);
        
        printf("reader(%u): %d\n", (unsigned int)pthread_self(), shared);

        sem_wait(&x);
        readerCount--;
        if(readerCount == 0){
            sem_post(&wSem);
        }
        sem_post(&x);
    }
    return NULL;
}
