/*====================================================================================================================================================================================
Name : 11.c
Author : Darshit Jakhaniya
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
            a. use dup
            b. use dup2
            c. use fcntl
Date: 18th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){

	//dup() system call will create copy of file descriptor and we can use both interchangably

	int fd = open("dup.txt", O_WRONLY | O_APPEND);
	
	if(fd < 0)
		printf("Error opening the file\n");
  
	int copy_fd = dup(fd);
		
	// write() will write the given string into the file referred by the file descriptors

	write(copy_fd,"This will be written by new file descriptor to the file named dup.txt\n", strlen("This will be written by new file descriptor to the file named dup.txt\n"));
		
	write(fd,"This will be written by old file descriptor to the file named dup.txt\n",strlen("This will be written by old file descriptor to the file named dup.txt\n"));

	int file_desc = open("dup2.txt",O_WRONLY | O_APPEND);
	
	 if(file_desc<0)
         {
          perror("ERROR :");
         }
      
        /* As in dup2(), in place of newfd any file descriptor can be put. Below is a C implementation in which the file descriptor of Standard output (stdout) is used.
	/* This will lead all the printf() statements to be written in the file referred by the old file descriptor.*/

         dup2(file_desc, 1) ; 
         printf("Hello how are you!...\n");
          
         //using fcntl
         fd=open("dup3.txt",O_RDWR|O_APPEND|O_CREAT,0644);
         int copied_fcntl = fcntl(fd, F_DUPFD,10);
         if(copied_fcntl<0)
         {
          perror("ERROR :");
         }
         write(fd,"writing using original file descriptor :\n",39);
         write(copied_fcntl,"writing using copied file descriptor :\n",37); 
         close(fd);
}

	
	return 0;
}

