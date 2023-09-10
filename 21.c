/*====================================================================================================================================================================================
Name : 21.c
Author : Darshit Jakhaniya
Description :Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
int main()
{
  pid_t pid=fork();
  if(pid==0)
  {
    printf("child process id:%d\n",getpid());
  }
  else
  {
    printf("parent process id:%d\n",getpid());
  }

}
