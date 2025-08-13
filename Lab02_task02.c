#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t a,b;
	
	a=fork();
	if(a<0){
		printf("Error in forking\n");
	}
	else if(a==0){
		b=fork();
		if(b<0){
			printf("Error in fork\n");
		}
		else if(b==0){
			printf("I am the grandchild\n");
		}
		else{
			wait(NULL);
			printf("I am child\n");
		}
	}
	else{
		wait(NULL);
		printf("I am parent\n");
	}
	return 0;
}

