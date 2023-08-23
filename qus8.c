#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

 

 int main() {
    FILE    *textfile;
    char buf[128];
     
    int fd = open("readme.txt", O_RDONLY);
    if(fd == -1)
        printf("Error in opening file");


    while(read(fd, &buf, sizeof(buf))){
        printf("%s",buf);
    }

     
    close(fd);
    return 0;
}
