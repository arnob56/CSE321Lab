#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t a,b ;

    
    a=fork();

    if (a< 0) {
        printf("Fork failed");
        return 1;
    }
    if (a==0) {
        printf("2. Child process ID: %d\n",getpid());

        for (int i=0;i<3;i++){
            b=fork();
            if (b<0){
                printf("Fork failed in grandchild");
                return 1;
            }
            if (b==0){
                printf("%d. Grand Child process ID:%d\n",i+3,getpid());
                return 0;
            }
            wait(NULL);
        }
    } else {
        printf("1. Parent process ID: %d\n", getpid());
        wait(NULL);
    }

    return 0;
}

