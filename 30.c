/*====================================================================================================================================================================================
Name : 30.c
Author : Darshit Jakhaniya
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 6th sept, 2023.
====================================================================================================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
int main(){
	pid_t pid;
	time_t current_time;
	struct tm exec_time;
	
	exec_time.tm_hour = 4;
	exec_time.tm_min = 25;
	exec_time.tm_sec = 0;
	
	while(1){
		time(&current_time); 
		//Adds current time in current_time
		struct tm* curr_time = localtime(&current_time);
		if(curr_time->tm_hour == exec_time.tm_hour && curr_time->tm_min == exec_time.tm_min){
			pid = fork(); 
			//create a child process to execute the script
			
			if(pid==0){
				execlp("ls","ls","-l",NULL); 
				// we want to excute ls with argument -l..execlp typically used to execute scripts
				exit(1);
			}
			else if(pid>0){
				int status;
				waitpid(pid,&status,0);
				//we can use waitpid() to wait for child to complete
				if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                   			 printf("Script executed successfully.\n");
                    			 break;
                		} 	
				else {
                    			printf("Script execution failed.\n");
                		}
			}
		} 
	sleep(60);
	//sleep for 60 seconds before checking the time again
	}
}
