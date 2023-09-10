/*====================================================================================================================================================================================
Name : 24.c
Author : Darshit Jakhaniya
Description :Write a program to create an orphan process.
Date: 2th sept, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
//A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.
int main()
{
pid_t child_pid=fork();

      //in the following code, parent finishes execution and exits while the child process is still executing and is called an orphan process now. 
      //However, the orphan process is soon adopted by init process, once its parent process dies.
      if(child_pid==0)
     {
         sleep(5); //child goes to sleep and in the meanwhile parent terminates
         printf("\nI am child having PID %d\n",getpid());
         printf("My parent PID is %d\n",getppid());
         printf("child process is adopted by init process\n");
     }
     else
     {
         printf("\nI am parent having PID %d\n",getpid());
         printf("My child PID is %d\n",child_pid);
     }
     return 0;
 }
