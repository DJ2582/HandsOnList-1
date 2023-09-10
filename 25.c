/*====================================================================================================================================================================================
Name : 25.c
Author : Darshit Jakhaniya
Description :Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 4th sept, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  int wstatus;
  pid_t ch_pid1;
  ch_pid1=fork();
  
  if(ch_pid1==0)
  {
   printf("First Child pid:%d\n",getpid());
   printf("first Child Parent pid:%d\n",getppid());
  }
  
  else
  {
      waitpid(ch_pid1, &wstatus, 0);
      pid_t ch_pid2=fork();
      if(ch_pid2==0)
      {
       printf("second Child pid:%d\n",getpid());
       printf("second Child Parent pid:%d\n",getppid());
      }
      else
      {
           //waitpid is used to wait for the termination of a specific child process
           //it takes several parameter as argument including process id of child to wait for and second argument is exit status of child process.
            waitpid(ch_pid2, &wstatus, 0);
            pid_t ch_pid3=fork();
            if(ch_pid3==0)
            {
             printf("third Child pid:%d\n",getpid());
             printf("third Child Parent pid:%d\n",getppid());
            }
            else{
            waitpid(ch_pid3, &wstatus, 0);
            printf("parent of all is:%d\n",getpid());
            }
      }
   
  }
}
