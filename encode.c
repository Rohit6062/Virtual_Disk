#include"vdisk_header.h"
bool encode(diskinfo* vdisk,unsigned long val){
    // this function will encode the number put it in array from givin position and return postion till squence is inserted
    unsigned long output = val;
    long bitreq = log_2(val);
    unsigned long lev=1;
    unsigned long exp = val;
    while(val > 3){
        lev++;
        val = log_2(val);
        output = output | (val << log_2(output));
    }
    bitreq = max(log_2(output),2) + 3;
    output = output | (lev << max(log_2(output),2));
    // read = disk[i];
    byte read = getc(vdisk->f);
    fseek(vdisk->f,-1,SEEK_CUR);
    read = (makeToget(8) << vdisk->currBit) & read;  
    while(bitreq>7){
        putc(read | (output >> (bitreq - vdisk->currBit)),vdisk->f);
        read = 0;
        bitreq = bitreq - vdisk->currBit;
        vdisk->currBit = 8;
    }
    // byte currbit = 8;
    while(bitreq!=0){
        if(vdisk->currBit < bitreq){
            read  = read | output >> ((bitreq - vdisk->currBit));
            bitreq = bitreq - vdisk->currBit;
            vdisk->currBit=8;
            putc(read,vdisk->f);
            read = 0;
        }
        else{
            read = read | output << (vdisk->currBit-bitreq);
            putc(read,vdisk->f);
            fseek(vdisk->f,-1,SEEK_CUR);
            vdisk->currBit = vdisk->currBit-bitreq;
            bitreq = 0;
        }
    }
    return true;
}

