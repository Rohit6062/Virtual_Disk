#include"vdisk_header.h"
ul filesCnt(diskinfo* vdisk){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    ul curr=1;
    ul totalbits=0;
    ul output = 0;
    while(curr!=0 && totalbits < vdisk->fileSize*8){
        curr = decode(vdisk);
        totalbits += ((curr*8) + getBitReq(curr));
        output++;
    }
    return output/2;
}
