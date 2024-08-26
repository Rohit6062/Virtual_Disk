#include<stdio.h>
#include<stdlib.h>
typedef unsigned char byte;
int main()
{
    FILE* vidsk = fopen("disk","wb");
    byte put = 0;
    for(int i=0;i<5242880;i++)
    {
        fwrite(&put,sizeof(put),1,vidsk);
    }
    printf("Done\n");
    return 0;
}
