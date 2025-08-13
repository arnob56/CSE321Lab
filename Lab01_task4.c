#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void sort(int arr[],int n) {
    for (int i=0;i<n-1;++i)
        for (int j=0;j<n-i-1;++j)
            if (arr[j]<arr[j + 1]) {
                int temp=arr[j];
                arr[j]=arr[j + 1];
                arr[j + 1]=temp;
            }
}

void parity_check(int arr[],int n) {
    for (int i=0;i<n;i++) {
        if (arr[i]%2!= 0)
            printf("%d is Odd\n",arr[i]);
        else
            printf("%d is Even\n",arr[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int n = argc-1;
    int arr[n];
    for (int i= 0; i < n; ++i)
        arr[i] = atoi(argv[i + 1]);

    pid_t a = fork();

    if (a<0) {
        printf("Fork failed");
        return 1;
    } else if (a==0) {
        sort(arr,n);
        printf("Sorted array in decending order: \n");
        for (int i=0;i<n;i++)
            printf("%d, ",arr[i]);
    } else {
        
        wait(NULL)
        printf("Parent Process parity check: ");
        checkOddEven(arr, n);
    }

    return 0;
}

