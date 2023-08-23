#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd1, fd2, fd3 ,fd4 ,fd5;
	fd1=open("file1", O_RDWR | O_CREAT);
	fd2=open("file2", O_RDWR | O_CREAT);
	fd3=open("file3", O_RDWR | O_CREAT);
        fd4=open("file4", O_RDWR | O_CREAT);
        fd5=open("file5", O_RDWR | O_CREAT);
	for(;;);
}

// first compile the program using "cc qus5.c" then run command "./a.out &" which will
// give the process id.
// then run command "cd /proc/pid"
// there is fd directory
// run command "ll ./fd"
// which will give information about the process
// then go to proc directory 
// run command "kill -9 pid"


