#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    char buf[512];
    read(0, buf, 32);
    write(1, buf, 32);
    return 0;
}
