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
