/*====================================================================================================================================================================================
Name : 9.c
Author : Darshit Jakhaniya
Description :Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 17th Aug, 2023.
====================================================================================================================================================================================*/
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>
int main(){


   struct stat sfile;
   stat("qus1.c", &sfile);

  printf("\ninode number:%ld",sfile.st_ino);
  printf("\nsize of the file:%ld",sfile.st_size);
  printf("\ntotal number of hard link:%lu", sfile.st_nlink);
  printf("\nuserid:%d", sfile.st_uid);
  printf("\nblock size:%ld", sfile.st_blksize);
  printf("\ngroup id:%d", sfile.st_gid);
  printf("\ntotal number of blocks:%ld", sfile.st_blocks);
  printf("\ntime of last access:%ld", sfile.st_atime);
  printf("\ntime of recent modification:%ld", sfile.st_mtime);
  printf("\ntime of last change:%ld\n",sfile.st_ctime);
}

