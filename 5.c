/*====================================================================================================================================================================================
Name : 5.c
Author : Darshit Jakhaniya
Description :Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 14th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd1, fd2, fd3 ,fd4 ,fd5;
	fd1=open("file1.txt", O_RDWR | O_CREAT);
	fd2=open("file2.txt", O_RDWR | O_CREAT);
	fd3=open("file3.txt", O_RDWR | O_CREAT);
        fd4=open("file4.txt", O_RDWR | O_CREAT);
        fd5=open("file5.txt", O_RDWR | O_CREAT);
	for(;;);
}

// first compile the program using "cc qus5.c" then run command "./a.out &" so process will run in background and will
// give the process id.
// then run command "cd /proc/pid"
// there is fd directory
// run command "ll ./fd"
// which will give information about the process
// then go to proc directory 
// run command "kill -9 pid"


