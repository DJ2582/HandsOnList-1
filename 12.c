/*====================================================================================================================================================================================
Name : 12.c
Author : Darshit Jakhaniya
Description :Write a program to find out the opening mode of a file. Use fcntl.
Date: 19th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){
	
	const char *filename = "qus12.c";

        int fileDescriptor = open(filename,O_RDWR);
        if (fileDescriptor == -1) {
        
        perror("Error opening file");
        return 1;
         }

        // Get the file access mode using fcntl
        int flags = fcntl(fileDescriptor, F_GETFL) & O_ACCMODE;
        //F_GETFL:  Return  (as  the  function  result) the file access mode and the file status flags; arg is ignored.
	//by performing end operation we will get value 0,1 or 2(0 for RDONLY,1 for WRONLY  2 for RDWR
	
        if (flags == -1) {
        perror("Error getting file flags");
        } 
        // Check the access mode and print the result
        if (flags==0) 
	{
        printf("File is opened in read-only mode.\n");
        }
	else if (flags==1) 
	{
        printf("File is opened in write-only mode.\n");
        } 
	else if (flags==2) 
	{
        printf("File is opened in read-write mode.\n");
        }
	else 
	{
        printf("Unknown file access mode.\n");
        }

        // Close the file
        close(fileDescriptor);

    return 0;
}
