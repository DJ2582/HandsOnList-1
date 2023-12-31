/*====================================================================================================================================================================================
Name : 14.c
Author : Darshit Jakhaniya
Description :Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.
Date: 20th Aug, 2023.
====================================================================================================================================================================================*/
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
      if(argc !=2){
        printf("not enough argument");
        return 1;
      }
      
      struct stat fi;
      if(stat(argv[1], &fi)==-1){
        perror("Error");
        return 1;
      }

      //S_ISREG() is posix macros which is used to interprete the value of struct sate member which is returned from stat system call.
      if (S_ISLNK(fi.st_mode)) {
          printf("Symbolic link\n");
      } 
      else if (S_ISREG(fi.st_mode)) {
          printf("Regular file\n");
      } 
      else if (S_ISDIR(fi.st_mode)) {
          printf("Directory\n");
      }
      else if (S_ISFIFO(fi.st_mode)) {
          printf("FIFO\n");
      } 
      else if (S_ISCHR(fi.st_mode)) {
          printf("Character special file\n");
      } 
      else if (S_ISBLK(fi.st_mode)) {
          printf("Block special file\n");
      } 
      else if (S_ISSOCK(fi.st_mode)) {
          printf("Socket\n");
      } 
      else {
          printf("Unknown file type\n");
      }
  
} 
