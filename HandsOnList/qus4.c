#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd = open("abc001.txt", O_RDWR | O_CREAT | O_EXCL);
	if(fd==0)
	{
		printf("already hai");
	}
        printf("fd = %d\n", fd);
	if(fd<0)
	{
		perror("Failed");
	}
	return 0;
}	
