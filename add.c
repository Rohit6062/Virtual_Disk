bool add(byte* name,int nlen,byte* data, int len){
    i=2;
    currbit=8;
    int tot=0; // total bytes including bits needed in encoding
    int tmp; // helper variable
    int cnt = count*2; // count of files and there names in disk
    unsigned long totUsed=0; // total bytes where actual data is stored
    while(cnt--){
        tmp=decode(currbit);
        totUsed += tmp;
        tot += getBitReq(tmp);
    }
    tot = ceil((float)tot/8) + totUsed;
    if((len+nlen) > (FILESIZE - tot - 2))return false;
    encode(nlen,currbit);
    encode(len,currbit);
    int k=0;
    int bound = FILESIZE - nlen - len - totUsed;
    while(k < nlen)
    {
        disk[k+bound] = name[k];
        k++;
    }
    bound += nlen;
    k=0;
    while(k<len)
    {
        disk[k+bound] = data[k];
        k++;
    }
    count = count + 1;
    return true;
}
