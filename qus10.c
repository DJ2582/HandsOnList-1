#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){
	int fd;
	char buf[10]="djakhaniya";
	fd=open("lseek.txt" , O_RDWR | O_CREAT);
	if(fd<0)
	{
		perror("Error");
	}
	write(fd, buf , strlen(buf));
	int f1=lseek(fd,10,SEEK_CUR);
	printf("pointer is at:%d",f1);
	char buff[10]="darshitbro";
	write(fd, buff , strlen(buff));
}

// to see on the terminal use the command "od -c lseek.txt"
