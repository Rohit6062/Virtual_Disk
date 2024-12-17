#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("enter ");
    char s[10000];
    fgets(s,10000,stdin);
    printf("%s",s);
    return 0;
}
