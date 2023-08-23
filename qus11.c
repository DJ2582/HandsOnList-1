#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){

	//dup() system call will create copy of file descriptor and we can use both interchangably

	int fd = open("dup.txt", O_WRONLY | O_APPEND);
	
	if(fd < 0)
		printf("Error opening the file\n");
	
	// dup() will create the copy of fd as the copy_fd
	// then both can be used interchangeably.

	int copy_fd = dup(fd);
		
	// write() will write the given string into the file
	// referred by the file descriptors

	write(copy_fd,"This will be written by new file descriptor to the file named dup.txt\n", strlen("This will be written by new file descriptor to the file named dup.txt\n"));
		
	write(fd,"This will be written by old file descriptor to the file named dup.txt\n",strlen("This will be written by old file descriptor to the file named dup.txt\n"));

	int file_desc = open("dup2.txt",O_WRONLY | O_APPEND);
      
        /* As in dup2(), in place of newfd any file descriptor can be put. Below is a C implementation in which the file descriptor of Standard output (stdout) is used.
	 * This will lead all the printf() statements to be written in the file referred by the old file descriptor.*/

        dup2(file_desc, 1) ; 
          
        
        printf("Hello how are you!...\n");

	
	return 0;
}

