#include"vdisk_header.h"
#include<stdio.h>
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


diskinfo* init(){ 
    diskinfo* vdisk =(diskinfo*) malloc(sizeof(diskinfo)); 
    vdisk->f = fopen("disk","r+");
    fseek(vdisk->f,0,SEEK_END);
    vdisk->fileSize = ftell(vdisk->f);
    vdisk->count = filesCnt(vdisk);
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit = 8;
    return vdisk;
}
void save(FILE* f){
    fseek(f,0,SEEK_SET);
    // fwrite(&count,sizeof(count),1,f);
    fclose(f);
}


