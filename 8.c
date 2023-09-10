/*====================================================================================================================================================================================
Name : 8.c
Author : Darshit Jakhaniya
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.
Date: 15th Aug, 2023.
====================================================================================================================================================================================*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main() {
    char buf[128];
     
    int fd = open("readme.txt", O_RDONLY);
    if(fd == -1)
        printf("Error in opening file");

    while(read(fd, buf, sizeof(buf)))
    {
        printf("%s",buf);
    }
    close(fd);
    return 0;
}
