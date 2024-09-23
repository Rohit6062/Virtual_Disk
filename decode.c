#include"vdisk_header.h"
long decode(diskinfo* vdisk){
    byte read = getc(vdisk->f);
    if(vdisk->currBit==0)read = fgetc(vdisk->f),vdisk->currBit=8;
    byte lvl;
    long output=0;
    long toget = 2;
    if(vdisk->currBit<3){
        if(vdisk->currBit==2) lvl = (3 & read) << 1 , read = getc(vdisk->f), lvl = lvl | (1 & (read >> 7)) , vdisk->currBit = 7;  
        else lvl =  (1 & read) << 2 , read = getc(vdisk->f) , lvl = lvl | (3 & (read >> 6)), vdisk->currBit = 6;
    } 
    else lvl = 7 & (read >> (vdisk->currBit - 3)), vdisk->currBit= vdisk->currBit-3;
    if(vdisk->currBit==0)vdisk->currBit=8,read = getc(vdisk->f);
    while(lvl--){
        output = 0;
        while(toget){
            if(toget<vdisk->currBit){
                output = output | (makeToget(toget) & (read >> (vdisk->currBit-toget)));  
                vdisk->currBit = vdisk->currBit-toget;
                toget = 0;
            }
            else{
                output = output |  (makeToget(vdisk->currBit) & read );
                toget -= vdisk->currBit;
                if(toget>8)output = output << 8;
                else output = output << toget;
                vdisk->currBit = 8;
                read = getc(vdisk->f);
            }
        }
        toget = output;
    }
    fseek(vdisk->f,-1,SEEK_CUR);
    return output;
}
