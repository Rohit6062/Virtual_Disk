#include"vdisk_header.h"
ul filesCnt(diskinfo* vdisk){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    ul curr=1;
    ul totalbits=0;
    ul output = 0;
    while(curr!=0 && totalbits < (vdisk->fileSize*8)){
        curr = decode(vdisk);
        printf("curr = %d\n", curr);
        totalbits += ((curr*8) + getBitReq(curr));
        if(is_bit_set(vdisk))output++;
        increament_bit(vdisk);
    }
    return output/2;
}
