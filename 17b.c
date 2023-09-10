/*====================================================================================================================================================================================
Name : 17b.c
Author : Darshit Jakhaniya
Description :Write a program to simulate online ticket reservation. Implement write lock Write a program to open a file, store a ticket number and exit. Write a separate program,
             to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 22th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
  struct{
        int tic_no;
    }ticket;
  
    struct flock lock;
    int fd = open("ticket.txt",O_RDWR);
    int tic;
    printf("Enter the ticket number:");
    scanf("%d", &tic);
    ticket.tic_no=tic;
    write(fd,&ticket,sizeof(ticket));
    close(fd);
    return 0;
    
}
