#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* f = fopen("vish","r+");
    printf("ftell(f) = %ld\n", ftell(f));
    fseek(f,1,SEEK_SET);
    printf("getc(f) = %c\n", getc(f));
    return 0;
}
