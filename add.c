#include"vdisk_header.h"
bool add(diskinfo* vdisk,byte* name,FILE* toadd){
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    int nlen = strlen(name);
    fseek(toadd,0,SEEK_END);
    int len = ftell(toadd);
    fseek(toadd,0,SEEK_SET);
    ul tot=0; // total bytes including bits needed in encoding
    ul tmp; // helper variable
    ui cnt = vdisk->count * 2; // count of files and there names in disk
    ul totUsed=0; // total bytes where actual data is stored
    byte* buffer = (byte*) calloc(10240, sizeof(byte)); 
    int buflen = 10240;
    // posinfo currinfo = {8,8};
    while(cnt--){
        tmp = decode(vdisk);
        totUsed += tmp;
        tot += getBitReq(tmp);
    }
    tot = ceil((float)tot/8) + totUsed;
    if((len+nlen) > (vdisk->fileSize - tot - 2))return 0;
    if(!encode(vdisk,nlen))return false;
    if(!encode(vdisk,len))return false;
    int k=0;
    fseek(vdisk->f,-nlen-len-totUsed-2,SEEK_END);
    fwrite(name,1,nlen,vdisk->f);
    while(len>0){
        if(len<buflen)buflen=len;
        fread(buffer,1,buflen,toadd);
        fwrite(buffer,1,buflen,vdisk->f);
        len-=buflen;
    }
    vdisk->count = vdisk->count + 1;
    return true;
}
