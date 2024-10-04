#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    char *input;
    int repeat;
} thread_args;

void *printChar(void *arg){
    thread_args *args = (thread_args *)arg; 
    pthread_t id = pthread_self();
    for(int i = 0; i < args->repeat; i++){
        printf("Thread(%lu): %s\n", (unsigned long)id, args->input);
    }
    return NULL;
}

int main(){
    char input[2][100];
    int repeat = 0;

    printf("Repeatitions: ");
    scanf("\n%d", &repeat);

    printf("Enter the first string: ");
    scanf("\n%s", input[0]);
    
    printf("Enter the second string: ");
    scanf("\n%s", input[1]);

    pthread_t thread[2];

    thread_args content[2];

    for(int i = 0; i < 2; i++){
        content[i].input = strdup(input[i]);
        content[i].repeat = repeat;
        pthread_create(&thread[i], NULL, printChar, (void *)&content[i]);
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < 2; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;

}