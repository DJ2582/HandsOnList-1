#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v=symlink("dest.txt","ddd");
	printf("%d",v);
	if(v<0)
	{perror("FAILED ");return 1;}

	int f=link("dest.txt","dddd");
	  if(f<0)
	  {perror("Failed");}

	int e= mknod("ddddd",S_IFIFO,0);

	if(e<0)
		perror("Failed");
	return 0;
}	
