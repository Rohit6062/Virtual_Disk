#include"vdisk_header.h"
void ls(diskinfo* vdisk){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit = 8;
    ui cnt =vdisk->count;
    ul ending = 2;
    ui tmp1;
    ui tmp2;
    ul tmpPos;
    char* spaces =(char*) malloc(76);
    byte* buffer = (byte*) malloc(sizeof(byte)*50);
    memset(spaces,32,50 - strlen("name:"));
    printf("\tName:%sSize:\n",spaces);
    bzero(spaces,75);
    while(cnt){
        tmp1 = decode(vdisk);
        increament_bit(vdisk);
        tmp2 = decode(vdisk);
        ending += tmp1+tmp2;
        if(is_bit_set(vdisk)){
            tmpPos = ftell(vdisk->f);
            printf("\t");
            fseek(vdisk->f,-ending,SEEK_END);
            fgets(buffer,tmp1+1,vdisk->f);
            // printf("%s",buffer);
            memset(spaces,32,50 - strlen(buffer));
            fseek(vdisk->f,tmpPos,SEEK_SET);
            printf("%s%s%d\n",buffer,spaces,tmp2);
            bzero(spaces,75);
            cnt--;
        }
        increament_bit(vdisk);
    }
}
