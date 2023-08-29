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
   
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();
    printf("Before Entering Into Critical Section\n");
    
    //set the write lock using F_SETLKW
    fcntl(fd,F_SETLKW,&lock);
    read(fd,&ticket,sizeof(ticket));
    printf("ticket no : %d\n",ticket.tic_no);
    
    //updating the value of tickets
    ticket.tic_no++;
    
    lseek(fd,0L,SEEK_SET);
    write(fd,&ticket,sizeof(ticket));
    //set the current pointer 
    printf("entered critical section\n");
    printf("enter for unlock : ");
    getchar();
    lock.l_type = F_UNLCK;
    printf("unlocked\n");
    fcntl(fd,F_SETLK,&lock);
    printf("done\n");
    return 0;
}
