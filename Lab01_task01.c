#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd;
    char buffer[1024];
    if (argc<2) {
        printf("%s <filename>\n",argv[0]);
        return 1;
    }

    fd = open(argv[1],O_RDWR| O_CREAT, 0644);
    if (fd == -1) {
        printf("Error opening file");
        return 1;
    }

    printf("%s opened for read/write access\n", argv[1]);

    while (true) {
        printf("Enter: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0]=='-' && buffer[1]=='1'&& buffer[2]=='\0') {
            printf("The System Quits");
            break;
        }
        write(fd,buffer,strlen(buffer));
        write(fd, "\n", 1);
    }
    close(fd);
    return 0;
}

