#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{

       int c;
       mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
       char *filename = "qus3.txt";
       c = creat(filename, mode);
       int fd = open(filename, O_RDONLY);

       printf("fd = %d\n" , fd);
       if(c<0){
	       perror("Failed");
       }
       return 0;

}

