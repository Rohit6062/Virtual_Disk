#include"vdisk_header.h"
bool delete(diskinfo* vdisk, byte* name){
    ui len  = strlen(name);
    byte* buffer  = (byte*) malloc(sizeof(byte)*50);
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit = 8;
    ui cnt = vdisk->count;
    ul ending = 2;
    ui tmp1;
    ui tmp2;
    // ul tmpPos1[2];
    // ui tmpPos2[2];
    while(cnt){
        tmp1 = decode(vdisk);
        if(!is_bit_set(vdisk)){
            ending+= tmp1;
            // printf("returnung\n");
            increament_bit(vdisk);
            continue;}
        ui tmpPos1[2] = {ftell(vdisk->f),vdisk->currBit};
        increament_bit(vdisk);
        tmp2 = decode(vdisk);
        ending+=tmp2+tmp1;
        if(is_bit_set(vdisk) && tmp1 == len){
            ui tmpPos2[2] = {ftell(vdisk->f),vdisk->currBit};
            fseek(vdisk->f,-ending,SEEK_END);
            fgets(buffer,tmp1+1,vdisk->f);
            printf("strncmp %s %s tmp->%d len->%d cnt->%d\n",buffer,name,tmp1,len,cnt);
            if(!strncmp(buffer,name,len)){
                fseek(vdisk->f,tmpPos1[0],SEEK_SET);
                vdisk->currBit = tmpPos1[1];
                set_bit(vdisk,false);
                fseek(vdisk->f,tmpPos2[0],SEEK_SET);
                vdisk->currBit = tmpPos2[1];
                set_bit(vdisk,false);
                vdisk->count-=1;
                return true;
            }
            fseek(vdisk->f,tmpPos2[0],SEEK_SET);
        }
        increament_bit(vdisk);
        cnt--;
    }
    return false;
}
