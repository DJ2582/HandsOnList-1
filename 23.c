/*====================================================================================================================================================================================
Name : 23.c
Author : Darshit Jakhaniya
Description :Write a program to create a Zombie state of the running program.
Date: 1st sept, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
    pid_t child_pid = fork();
    
    //A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process.
    //A child process always first   becomes a zombie before being removed from the process table.
    
    
    // Parent process 
    if (child_pid > 0)
    {
        printf("parent process id is:%d\n",getpid());
        sleep(10);
    }
    // Child process
    else
    {
        printf("child process id is:%d\n",getpid());
        exit(0);
     }
    return 0;
}
