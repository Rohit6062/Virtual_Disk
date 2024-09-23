#include"vdisk_header.h"
bool view(diskinfo* vdisk,ui n){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    if(vdisk->count < n)return false;
    int tmp = n;
    int nlen=0;
    int len=0;
    int bound=0;
    while(tmp--){
        nlen = decode(vdisk);
        len= decode(vdisk);
        bound += nlen + len;
    }
    tmp = 0;
    fseek(vdisk->f,-bound-2,SEEK_END);
    while(tmp < nlen){
        printf("%c",getc(vdisk->f));
        tmp++;
    }
    printf(" \n");
    bound -= nlen;
    tmp = 0;
    while(tmp < len){
        printf("%c",getc(vdisk->f));
        tmp++;
    }
    printf(" \n");
    return true;
}

bool get(diskinfo* vdisk,byte* name){
    ui len  = strlen(name);
    byte* buffer  = (byte*) malloc(sizeof(byte)*50);
    ui cnt = vdisk->count;
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    ul ending = 2;
    ui tmp;
    ul tmpPos;
    while(cnt--){
        tmp = decode(vdisk);
        ending = decode(vdisk) +tmp + ending;
        if(tmp == len){
            tmpPos = ftell(vdisk->f);
            fseek(vdisk->f,-ending,SEEK_END);
            fgets(buffer,len+1,vdisk->f);
            if(strncmp(buffer,name,len)==0)return view(vdisk,vdisk->count-cnt);
            fseek(vdisk->f,tmpPos,SEEK_SET);
        }
    }
    return false;
}
