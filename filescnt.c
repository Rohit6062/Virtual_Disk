ul filesCnt(FILE* f){
    fseek(f,0,SEEK_SET);
    currbit = 8;
    ul curr=1;
    ul totalbits=0;
    ul output = 0;
    while(curr!=0 && totalbits < FILESIZE*8){
        curr = decode(currbit,f);
        totalbits += ((curr*8) + getBitReq(curr));
        output++;
    }
    return output/2;
}



