#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	int fd = open("busrecord.txt", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("error in opening file");
	}
	else
	{
		printf("Enter three different values separated by a single space");
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		write(fd, &x, sizeof(x));
		write(fd, &y, sizeof(y));
		write(fd, &z, sizeof(z));
		close(fd);
	}
	return 0;
}
