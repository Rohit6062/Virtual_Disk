#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *c = (char*) malloc(sizeof(char)*10);
    memset(c,32,9);
    printf("c = %s %d\n", c,1);
    return 0;
}
