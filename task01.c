#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int fibCount;
int *fibNumbers;
int searchCount;
int *searchList;

void *makeFibonacci(void *arg) {
    fibNumbers = (int *)malloc((fibCount + 1) * sizeof(int));

    for (int i = 0; i <= fibCount; i++) {
        if (i == 0) fibNumbers[i] = 0;
        else if (i == 1) fibNumbers[i] = 1;
        else fibNumbers[i] = fibNumbers[i - 1] + fibNumbers[i - 2];
    }
    pthread_exit(NULL);
}

void *findFibonacci(void *arg) {
    for (int i = 0; i < searchCount; i++) {
        int index = searchList[i];
        if (index >= 0 && index <= fibCount)
            printf("result of search #%d = %d\n", i + 1, fibNumbers[index]);
        else
            printf("result of search #%d = -1\n", i + 1);
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t thread1, thread2;

    printf("Enter the term of fibonacci sequence:\n");
    scanf("%d", &fibCount);
    if (fibCount < 0 || fibCount > 40) {
        printf("Invalid number. Must be between 0 and 40.\n");
        return 1;
    }

    printf("How many numbers you are willing to search?:\n");
    scanf("%d", &searchCount);
    if (searchCount <= 0) {
        printf("Number of searches must be greater than 0.\n");
        return 1;
    }

    searchList = (int *)malloc(searchCount * sizeof(int));

    for (int i = 0; i < searchCount; i++) {
        printf("Enter search %d:\n", i + 1);
        scanf("%d", &searchList[i]);
    }

    pthread_create(&thread1, NULL, makeFibonacci, NULL);
    pthread_join(thread1, NULL);

    for (int i = 0; i <= fibCount; i++)
        printf("a[%d] = %d\n", i, fibNumbers[i]);

    pthread_create(&thread2, NULL, findFibonacci, NULL);
    pthread_join(thread2, NULL);

    free(fibNumbers);
    free(searchList);
    return 0;
}


