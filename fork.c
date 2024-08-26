#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){ 
    pid_t p ;
    FILE* f2 = fopen("f2.txt","w");
    char str[50];
    int re;
    char *args[3]; /* array to hold arguments to pass to exec system call */
    args[0]= "main";
    args[1]= "-l";
    args[2]= NULL;

    p =fork();
    if(p==0){
        re = execv("main", (char **) args);
    }
    else{
        printf("Enter the string: \n");
        scanf("%s",str);
        fwrite(str,strlen(str),1,f2);
        fclose(f2);
    }
    return 0;
}
