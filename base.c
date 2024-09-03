#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
typedef unsigned char byte;
typedef short unsigned int si;
typedef unsigned int ui;
typedef unsigned long ul;

si count;
FILE* f;
byte* disk;
ul currByte;
byte read;
ui i=0;
byte currbit=8;
ui FILESIZE;

long log_2(unsigned long x){
    long output=0;
    while(x){
        output++;
        x=x>>1;
    }
    return output;
}

ul max(ul a,ul b){return (a>b)?a:b;}

byte getBitReq(ul x){
    byte output = 0;
    while(x>3){
        x = log_2(x);
        output += x;
    }
    output+=5;
    return output;
}


void pl(long long val){
    unsigned long x = 1;
    x = x << 63;
    int cnt=0;
    while(x){
        cnt++;
        printf("%d",(val & x) == x);
        x = x >> 1;
        if(cnt%8==0)printf(" ");
    }
    printf("\n");
} 

long makeToget(long x){
    long output =0;
    while(x--)output = (output << 1) | 1;
    return output;
}

void pb(byte val){
    byte x = 1;
    x = x << 7;
    while(x){
        printf("%d",(val & x) == x);
        x = x >> 1;
    }
    printf(" ");
} 


void init(){ 
    f = fopen("disk","r+");
    fseek(f,0,SEEK_END);
    FILESIZE = ftell(f);
    fseek(f,0,SEEK_SET);
    // printf("Number of Files Stored = %d\n", count);
}
void save(){
    fseek(f,0,SEEK_SET);
    // fwrite(&count,sizeof(count),1,f);
    fclose(f);
}
