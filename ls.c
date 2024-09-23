#include"vdisk_header.h"
void ls(diskinfo* vdisk){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit = 8;
    ui cnt =vdisk->count;
    ul ending = 2;
    ui tmp1;
    ui tmp2;
    ul tmpPos;
    byte* buffer = (byte*) malloc(sizeof(byte)*50);
    printf("\tName:\t\tsize:\n");
    // posinfo currinfo =  {8,8};
    while(cnt--){
        tmp1= decode(vdisk);
        tmp2= decode(vdisk);
        ending += tmp2 + tmp1;
        tmpPos = ftell(vdisk->f);
        printf("\t");
        fseek(vdisk->f,-ending,SEEK_END);
        fgets(buffer,tmp1+1,vdisk->f);
        printf("%s ",buffer);
        fseek(vdisk->f,tmpPos,SEEK_SET);
        printf("\t%d",tmp2);
        printf("\n");
    }
}
