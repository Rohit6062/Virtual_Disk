#include"vdisk_header.h"

// increament bit by one
void increament_bit(diskinfo* vdisk){
    if(vdisk->currBit)vdisk->currBit--;
    else fseek(vdisk->f,1,SEEK_CUR),vdisk->currBit=8;
}

// this will just check if current bit is set or not 
bool is_bit_set(diskinfo* vdisk) 
{
    if(!vdisk->currBit)increament_bit(vdisk);
    byte read = fgetc(vdisk->f);
    fseek(vdisk->f,-1,SEEK_CUR);
    return (read & (1 << (vdisk->currBit-1)));
}

// this function will set bit according to flag and increament the bit 
void set_bit(diskinfo* vdisk,bool value){
    byte map[8] = {254,253,251,247,139,223,191,127};
    if(vdisk->currBit){
        byte read = fgetc(vdisk->f);
        vdisk->currBit = vdisk->currBit - 1; 
        if(value)read = read | (1 << vdisk->currBit);
        else read = read & (map[vdisk->currBit]);
        fseek(vdisk->f,-1,SEEK_CUR);
        putc(read,vdisk->f);
        if(vdisk->currBit)fseek(vdisk->f,-1,SEEK_CUR);
        else vdisk->currBit = 8;
    }
    else{
        fseek(vdisk->f,1,SEEK_CUR);
        set_bit(vdisk,value);
    }
}

bool add(diskinfo* vdisk,byte* name,FILE* toadd){
    printf("toadd = %p\n", toadd);
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
    while(cnt){
        tmp = decode(vdisk);
        totUsed += tmp;
        tot += getBitReq(tmp);
        if(is_bit_set(vdisk)){
            cnt--;
        }
        increament_bit(vdisk);
    }
    tot = tot + totUsed*8;
    if((len*8+nlen*8+2) > (vdisk->fileSize*8 - tot - 16))return 0;
    if(!encode(vdisk,nlen))return false;
    set_bit(vdisk,true);
    if(!encode(vdisk,len))return false;
    set_bit(vdisk,true);
    
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
