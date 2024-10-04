#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MATRIX_SIZE 1000
#define NUMBER_REPEATED 6

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int result = 0;

typedef struct{
    int matrix[MATRIX_SIZE];
    int size;
} thread_args;

void *countEquals(void *args){
    thread_args *content = (thread_args *)args;
    int count = 0;
    for(int i = 0; i < content->size; i++){
        if(content->matrix[i] == NUMBER_REPEATED){
            count++;
        }
    }
    pthread_t id = pthread_self();
    printf("Thread(%lu): %d\n", (unsigned long)id, count);
    pthread_mutex_lock(&mutex1);
    result += count;
    pthread_mutex_unlock(&mutex1);

    return NULL;

}


int assert(int matrix[1000]){
    int count = 0;
    for(int i = 0; i < 1000; i++){
        if(matrix[i] == NUMBER_REPEATED){
            count++;
        }
    }
    return count;
}


int main(){
    int matrix[MATRIX_SIZE];
    srand(time(NULL));
    int splits = 0;


    printf("Number of Splits: ");
    scanf("%d", &splits);
    
    for(int i = 0; i < MATRIX_SIZE; i++){
        matrix[i] = rand() % 10;
    }

    thread_args content[splits];
    int count = 0;
    int split_size = MATRIX_SIZE / splits;

    for(int i = 0; i<splits; i++){
        count = i * split_size;
        for (int j = count; j < count + split_size; j++){
            content[i].matrix[j-count] = matrix[j];
            content[i].size = split_size;
        }
    }    
    

    pthread_t threads[splits];
    
    for(int i = 0; i < splits; i++){
        pthread_create(&threads[i], NULL, countEquals, (void *)&content[i]);
    }

    for(int i = 0; i < splits; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Result: %d\n", result);
    printf("Assert: %d\n", assert(matrix));


    return 0;
}
