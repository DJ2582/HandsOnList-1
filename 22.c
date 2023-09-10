/*====================================================================================================================================================================================
Name : 22.c
Author : Darshit Jakhaniya
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 30th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
   int fd=open("qus22_fork.txt",O_RDWR);
   if(fork()==0)
   {
     printf("inside the child process\n");
     write(fd,"this is written by child process\n",33);
   }
   else
   {
     printf("inside the parent process\n");
     write(fd,"this is written by parent process\n",34);
   }
   return 0;
}
