#include<stdio.h>
#include<time.h>

#define N 100000

int main(){
    int arr[N];

    for(int i=0; i < N; i++){
        arr[i] = (i % 10000) + 1;  // Ensures values range from 1 to 10000
    }

    int even_count = 0, odd_count = 0;

    // Starting execution time
    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    // end execution time
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
 
    printf("Total Even Numbers: %d\n", even_count);
    printf("Total Odd Numbers: %d\n", odd_count);
    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}