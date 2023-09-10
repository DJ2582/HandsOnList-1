/*====================================================================================================================================================================================
Name : 13.c
Author : Darshit Jakhaniya
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not
            (check in $man 2 select).
Date: 19th Aug, 2023.
====================================================================================================================================================================================*/
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    int retval;
    fd_set rfds;
    struct timeval tv;
    
    FD_ZERO(&rfds);
    //FD_ZERO() clears (removes all file descriptors from) set.
    FD_SET(0,&rfds);
    //FD_SET adds the file descriptor fd to set.
    
    /*--> syntex: select(int nfds, readfds, writefds, exceptionalfds, timeout)
-->nfds: value of nfds will be  highest available file descriptor plus one
-->readfds:The file descriptors in this set are watched to see if they  are ready  for reading.
-->writefds:The file descriptors in this set are watched to see if they  are ready  for writng.
-->exceptfds:The file descriptors in this set are  watched  for  "exceptional conditions".
-->The  timeout  argument is a timeval structure (shown below) that specifies the interval that select() should block waiting for a file  descriptor to become ready.*/
 
    tv.tv_sec =10;
    printf("please wait for 10 seconds\n");
    retval = select(1, &rfds, NULL, NULL, &tv);
    // here first argument is nfds
   
    if (retval == -1)
         perror("select()");
    else if (retval)  
         printf("Data is available now.\n");
         //FD_ISSET(0, &rfds) will be true. FD_ISSET is used to check that file descriptor is stll in the set or not
    else
         printf("your time is over thanks!....\n");

   return 0;

}
