/*====================================================================================================================================================================================
Name : 15.c
Author : Darshit Jakhaniya
Description :Write a program to display the environmental variable of the user (use environ)
Date: 20th Aug, 2023.
====================================================================================================================================================================================*/
#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
// Most of the C compilers support a third parameter to main which store all environment variables
int main()
{
	extern char **environ;
	int i=0;
	while(environ[i])
	{
	printf("%s\n",environ(i++));
	}

}

