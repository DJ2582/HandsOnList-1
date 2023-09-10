/*====================================================================================================================================================================================
Name : 2.c
Author : Darshit Jakhaniya
Description :Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding
             proc directory. 
Date: 11th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
int main()
{
	while(1)
	{
	}
	return 0;
}
// first of all compile the this file using gcc qus2.out
// then run command ./a.out &, which gives the pid of this process
// then go to proc directory and run "ps" command which will show the that there is process running in background
// now kill the process using "kill -9 pid" command.
