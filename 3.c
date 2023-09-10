/*====================================================================================================================================================================================
Name : 3.c
Author : Darshit Jakhaniya
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 12th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{

       int c;
       mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
       char *filename = "qus3.txt";
       c = creat(filename, mode);
       printf("%d\n",c);
       int fd = open(filename, O_RDONLY);

       printf("fd = %d\n" , fd);
       if(c<0){
	       perror("Failed");
       }
       return 0;

}

