byte encode(FILE* f,unsigned long val,byte pos){
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
    read = getc(f);
    fseek(f,-1,SEEK_CUR);
    read = (makeToget(8) << pos) & read;  
    while(bitreq>7){
        putc(read | (output >> (bitreq - pos)),f);
        read = 0;
        bitreq = bitreq - pos ;
        pos = 8;
    }
    currbit = 8;
    while(bitreq!=0){
        if(pos < bitreq){
            read  = read | output >> ((bitreq - pos));
            bitreq = bitreq - pos;
            pos=8;
            putc(read,f);
            read = 0;
        }
        else{
            read = read | output << (pos-bitreq);
            // disk[i] = read; 
            putc(read,f);
            fseek(f,-1,SEEK_CUR);
            currbit = pos-bitreq;
            bitreq = 0;
        }
    }
    return 8-bitreq;
}


