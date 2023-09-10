/*====================================================================================================================================================================================
Name : 1.c
Author : Darshit Jakhaniya
Description : Create the following types of a files using (i) shell command (ii) system call
              a. soft link (symlink system call)
              b. hard link (link system call)
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 11th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v=symlink("dest.txt","softlink");
	printf("%d",v);
	if(v<0)
	{perror("FAILED ");return 1;}

	int f=link("dest.txt","hardlink");
	  if(f<0)
	  {perror("Failed");}

	int e= mknod("myfifo_file",S_IFIFO | 0666);  //third argument is optional

	if(e<0)
		perror("Failed");
	return 0;
}	
