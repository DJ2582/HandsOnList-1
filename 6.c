/*====================================================================================================================================================================================
Name : 6.c
Author : Darshit Jakhaniya
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 15th Aug, 2023.
====================================================================================================================================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    char buf[10];
    read(0, buf, 10);
    write(1, buf, 10);
    return 0;
}
