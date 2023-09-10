/*====================================================================================================================================================================================
Name : 10.c
Author : Darshit Jakhaniya
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 18th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include<string.h>
int main(){
	int fd;
	char buf[10]="djakha iya";
	fd=open("lseek.txt" , O_RDWR | O_CREAT);
	if(fd<0)
	{
		perror("Error");
	}
	write(fd, buf , strlen(buf));
	int f1=lseek(fd,10,SEEK_CUR);
	printf("pointer is at:%d",f1);
	char buff[10]="darsh tbro";
	write(fd, buff , strlen(buff));
}

// to see on the terminal use the command "od -c lseek.txt"  "od -a lseek.txt"  will also show the space
//od stands for octal dump
