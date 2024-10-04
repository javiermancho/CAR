#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 3

typedef struct {
    int row;
    int matrix1[3];
    int matrix2[3];
} thread_args;

int result[3][3];


void *matrix_sum(void *arg){
    thread_args *args = (thread_args *)arg;
    pthread_t id = pthread_self();
    for(int i = 0; i < 3; i++){
        result[args->row][i] = args->matrix1[i] + args->matrix2[i];
    }
    return NULL;
}


int main(){
    // int matrix1[3][3];
    // int matrix2[3][3];
    
    // printf("Enter the first matrix:\n");
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         scanf("%d", &matrix1[i][j]);
    //     }
    // }

    // printf("Enter the second matrix:\n");
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         scanf("%d", &matrix2[i][j]);
    //     }
    // }

    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[3][3] = {
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7}
    };

    pthread_t threads[THREAD_COUNT];
    thread_args content[THREAD_COUNT];

    for(int i = 0; i<3; i++){
        content[i].row = i;
        for(int j = 0; j < 3; j++){
            content[i].matrix1[j] = matrix1[i][j];
            content[i].matrix2[j] = matrix2[i][j];
        }
    }

    for(int i = 0; i < THREAD_COUNT; i++){
        pthread_create(&threads[i], NULL, matrix_sum, (void *)&content[i]);
    }

    for(int i = 0; i < THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Result:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}