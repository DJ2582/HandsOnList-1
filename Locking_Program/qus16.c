# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
int main()
{
    struct flock lock;
    int fd;
  
  
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();
    lock.l_type = F_WRLCK;
    fd = open("lseek.txt",O_RDWR);
    printf("before entering into critical section with write lock\n");
    int gotlck=fcntl(fd,F_SETLKW,&lock);
    if(gotlck==-1)
    {
      printf("error in acquiring write lock :\n");
    }
    else
    {
      printf("write lock acquired\n");
    }
    printf("press any key to release the write lock\n");
    getchar();
    lock.l_type=F_UNLCK;
    gotlck=fcntl(fd, F_SETLK,&lock);
    printf("exiting from the critical section and write lock released\n");
    
    printf("before entering into critical section with read lock\n");
    lock.l_type=F_RDLCK;
   
    gotlck=fcntl(fd,F_SETLKW,&lock);
    if(gotlck==-1)
    {
      printf("error in acquiring read lock :\n");
    }
    else
    {
      printf("read lock acquired\n");
    }
    printf("press any key to release the read lock\n");
    getchar();
    lock.l_type=F_UNLCK;
    gotlck=fcntl(fd, F_SETLK,&lock);
    printf("exiting from the critical section and read lock released\n");
    
    close(fd);
  
    
}
