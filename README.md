# CAR
CAR practical work

## Practical Work 1

The .c files are loacated in **threads_c** folder.

To compile the exercices use:

```bash
gcc -lpthread <file.c> -o <name> 
```

### String Repetition
The exercise involves creating a basic program to understand the functioning of threads. The functionality includes prompting the user for two strings and a number 𝑛 representing the number of repetitions. Each string will be passed as an argument to two threads, along with the number of repetitions. Each thread must print its ID and the corresponding string repeated 𝑛 times.

```bash
gcc -lpthread repeat_string.c -o repeat
./repeat 
```

### Matrix Sum

In this second exercise, the program is designed to perform matrix addition using threads. The number of threads created will be equal to the number of rows in each matrix, with each thread responsible for adding one row of Matrix 1 to the corresponding row of Matrix 2. The result of the addition for each row will be stored and displayed at the end of the process. To verify the functionality, we have decided to predefine matrices that will allow us to monitor the results.

```bash
gcc -lpthread matrix.c -o matrix
./matrix 
```

### Occurrences Counter
This final exercise has a very simple objective: to count the number of occurrences of a specific digit in an array of 20 elements. This will be achieved using 4 different threads, each of which will search in a sub-array of 5 elements. In our case, we have decided to parameterize the size of the array and the number of threads to be used.

```bash
gcc -lpthread mutex.c -o mutex
./mutex 
```
