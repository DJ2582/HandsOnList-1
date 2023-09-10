/*====================================================================================================================================================================================
Name : 18b.c
Author : Darshit Jakhaniya
Description :Write a program to perform Record locking.
            a. Implement write lock
            b. Implement read lock
            Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition
Date: 22th Aug, 2023.
====================================================================================================================================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	int fd = open("busrecord.txt", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("error in opening file");
	}
	else
	{
		printf("Enter three different values separated by a single space:");
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		write(fd, &x, sizeof(x));
		write(fd, &y, sizeof(y));
		write(fd, &z, sizeof(z));
		close(fd);
	}
	return 0;
}
