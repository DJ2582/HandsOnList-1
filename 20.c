/*====================================================================================================================================================================================
Name : 20.c
Author : Darshit Jakhaniya
Description :Find out the priority of your running program. Modify the priority with nice command.
Date: 26th Aug, 2023.
====================================================================================================================================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<sys/resource.h>
int main()
{
  int currentpriority;
  currentpriority=getpriority(PRIO_PROCESS,0);
  //by default current priority of the process will be 0
  //PRIO_PROCESS: to retrieve the priority of a specified process identified by its pid.  
  printf("priority of current process is:%d\n",currentpriority);
  
  nice(15);   //nice is used to set the desired value of priority of the process
  //nice is used when starting of new process.it allows you to specify the initial priority of process.
  //syntax: nice -n 10 <command> (command means process that you want to run ex: you want to start text editor(gedit).  nice -n 10 gedit
  //renice is used to change the priority of an already running process.it allows you to adjust the priority of existing process.
  //syntax: renice -n 10 -p <pid>

  int newpriority = getpriority(PRIO_PROCESS,getpid());  //getpriority() is methode used to get the priority of the process
  printf("priority of new process is:%d\n",newpriority);
  fflush(stdin);
  getchar();
  return 0;
}
