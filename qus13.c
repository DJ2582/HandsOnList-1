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

    tv.tv_sec =10;
    printf("please wait for 10 seconds\n");
    retval = select(2, &rfds, NULL, NULL, &tv);
    // here first argument is nfds
   
    if (retval == -1)
         perror("select()");
    else if (retval)
         printf("Data is available now.\n");
         /* FD_ISSET(0, &rfds) will be true. */
    else
         printf("your time is over thanks!....\n");

   return 0;

}
