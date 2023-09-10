/*====================================================================================================================================================================================
Name : 27.c
Author : Darshit Jakhaniya
Description :Write a program to execute ls -Rl by the following system calls
              a. execl
              b. execlp
              c. execled.
              d. execv
              e. execvp
Date: 5th sept, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
 char choice;
  printf("enter the system call from given below exec family:\n");
  printf("a) execl\nb) execlp\nc) execv\nd) execvp\ne) execle\n");
  scanf("%c", &choice);
  
  switch (choice) {
     case 'a':
          execl("/bin/ls", "ls", "-RL",NULL);
          break;
     case 'b':
          execlp("ls", "ls", "-RL",NULL);
          break;
     case 'c':
          char *args[]={"/bin/ls","-RL",NULL};
          execv("/bin/ls", args);
          break;
     case 'd':
          char *argv[]={"ls","-RL",NULL};
          execvp("ls", argv);
          break;
     case 'e':
          char* env[]={NULL};
          execle("/bin/ls", "ls", "-RL",NULL,env);
          break;
     default:
          printf("wrong option selected\n");
          break;
    }
  return 0;
}
