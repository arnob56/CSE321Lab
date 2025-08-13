#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    int count=1;
    pid_t a,b,c;
    a=fork();
    if (a==0) {
        if (getpid() %2!=0) {
            fork();
            count++;
        }
    } else {
        count++;
        b =fork();
        if (b ==0) {
            if (getpid()%2!=0) {
                fork();
                count++;
            }
        } else {
            count++;
            c=fork();
            if (c==0) {
        
                if (getpid()%2!=0) {
                    fork();
                    count++;
                }
            } else {
                count++;
            }
        }
    }

printf("Total Process:%d\n", count);
    return 0;
}

