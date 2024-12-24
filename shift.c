void shift(diskinfo* vdisk){
    bool got_space = false;
    bool got_occupied = false;
    ui cnt = vdisk->count;
    ui tmp1;
    ui buffersize = 10240;
    ui ending = 2;
    ui tmp2 = 0;
    while(cnt){
        tmp1 = encode(vdisk);
        ui tmpPos[2] = {ftell(vdisk->f),vdisk->currBit};
        if(is_bit_set(vdisk) && !got_empty_space){
            increament(vdisk);
            cnt--;
        }
        else if(is_bit_set(vdisk) && got_empty_space){
            fseek(vdisk->f,-ending,SEEK_END);
            if(tmp1<=buffersize)
                fgets(buffer,tmp1+1,vdisk->f),
                fseek(vdisk->f,empty_size,SEEK_CURR),
                fwrite(buffer,tmp1,vdisk->f),
                fseek(vdisk->f,tmpPos[0],SEEK_SET);
            else{
                ui shiftval = buffersize;
                while(tmp1){
                    fseek (vdisk->f,-shiftval,SEEK_CURR);
                    fgets (buffer,shiftval+1,vdisk->f );
                    fseek (vdisk->f,-shiftval+empty_size,SEEK_CURR);
                    fwrite(buffer,tmp1,vdisk->f);
                    fseek (vdisk->f,-empty_size-shiftval,SEEK_CURR);
                    tmp1-=shiftval;
                    if(tmp1<shiftval)shiftval=tmp1;
                }
            }
            cnt--;
            empty_size = 0;
            got_empty_space = false;
        }
        else{
            got_empty_space = true;
            empty_size += tmp1;
        }
        ending+=tmp1;
    }
}
