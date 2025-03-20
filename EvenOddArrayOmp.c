#include <omp.h>
#include <stdio.h>

#define N 1000000  //Size of the array
#define NUM_THREADS 4 //number of threads
#define CHUNK_SIZE 1000  // chunk size for both statoc and parallel
int main() {
    int arr[N];

    
    for (int i = 0; i < N; i++) {
        arr[i] = (i % 10000) + 1;  // Ensures values range from 1 to 10000
    }

    int even_static = 0, odd_static = 0;
    int even_dynamic = 0, odd_dynamic = 0;

    omp_set_num_threads(NUM_THREADS);   //define the number of threads for openMP region

    // ----------- STATIC SCHEDULING -----------
    double start_static = omp_get_wtime();

    #pragma omp parallel for schedule(static , CHUNK_SIZE) reduction(+:even_static, odd_static)
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0)
            even_static++;
        else
            odd_static++;
    }

    double end_static = omp_get_wtime();
    double time_static = end_static - start_static;

    // ----------- DYNAMIC SCHEDULING -----------
    double start_dynamic = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic , CHUNK_SIZE) reduction(+:even_dynamic, odd_dynamic)
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0)
            even_dynamic++;
        else
            odd_dynamic++;
    }

    double end_dynamic = omp_get_wtime();
    double time_dynamic = end_dynamic - start_dynamic;

    // Printing results
    printf("Using Static Scheduling:\n");
    printf("Even Numbers: %d, Odd Numbers: %d\n", even_static, odd_static);
    printf("Execution Time (Static): %f seconds\n\n", time_static);

    printf("Using Dynamic Scheduling:\n");
    printf("Even Numbers: %d, Odd Numbers: %d\n", even_dynamic, odd_dynamic);
    printf("Execution Time (Dynamic): %f seconds\n", time_dynamic);

    return 0;
}
