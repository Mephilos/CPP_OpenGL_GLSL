#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void* threadFunction(void* arg)
{
    int threadNum = *(int*)arg;
    printf("스레드 %d 시작. \n", threadNum);
    sleep(1); //1초 대기
    printf("스레드 %d 종료. \n", threadNum);
    free(arg);
    return NULL;
}

int main()
{
    const int NUM_THREADS = 10;
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        int* threadNum = (int*)malloc(sizeof(int));
        *threadNum = i + 1;

        if(pthread_create(&threads[i], NULL, threadFunction, threadNum) != 0 )
        {
            perror("스레드 생성 실패");
            free(threadNum);
        }
    }
        
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("모든 스레드가 종료됨. \n");
    return 0;
    
}