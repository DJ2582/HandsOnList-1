/*====================================================================================================================================================================================
Name : 4.c
Author : Darshit Jakhaniya
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 12th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd = open("abc001.txt", O_RDWR | O_CREAT | O_EXCL);
	if(fd<0)
	{
		perror("Failed");
	}
	/*if(fd==0)
	{
		printf("already hai");
	}*/
        printf("fd = %d\n", fd);
	
	return 0;
}	
