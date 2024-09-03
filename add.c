bool add(byte* name,FILE* toadd){
    fseek(f,0,SEEK_SET);
    int nlen = strlen(name);
    fseek(toadd,0,SEEK_END);
    int len = ftell(toadd);
    fseek(toadd,0,SEEK_SET);
    currbit=8;
    int tot=0; // total bytes including bits needed in encoding
    int tmp; // helper variable
    int cnt = count*2; // count of files and there names in disk
    unsigned long totUsed=0; // total bytes where actual data is stored
    byte* buffer = (byte*) calloc(10240, sizeof(byte)); 
    int buflen = 10240;
    while(cnt--){
        tmp=decode(currbit,f);
        totUsed += tmp;
        tot += getBitReq(tmp);
    }
    tot = ceil((float)tot/8) + totUsed;
    if((len+nlen) > (FILESIZE - tot - 2))return false;
    encode(f,nlen,currbit);
    encode(f,len,currbit);
    int k=0;
    fseek(f,-nlen-len-totUsed-2,SEEK_END);
    fwrite(name,1,nlen,f);
    while(len>0){
        if(len<buflen)buflen=len;
        fread(buffer,1,buflen,toadd);
        fwrite(buffer,1,buflen,f);
        len-=buflen;
    }
    count = count + 1;
    return true;
}
// bool add(byte* name,int nlen,byte* data, int len){
//     fseek(f,0,SEEK_SET);
//     currbit=8;
//     int tot=0; // total bytes including bits needed in encoding
//     int tmp; // helper variable
//     int cnt = count*2; // count of files and there names in disk
//     unsigned long totUsed=0; // total bytes where actual data is stored
//     while(cnt--){
//         tmp=decode(currbit,f);
//         totUsed += tmp;
//         tot += getBitReq(tmp);
//     }
//     tot = ceil((float)tot/8) + totUsed;
//     if((len+nlen) > (FILESIZE - tot - 2))return false;
//     encode(f,nlen,currbit);
//     encode(f,len,currbit);
//     int k=0;
//     int bound = FILESIZE - nlen - len - totUsed;
//     fseek(f,-nlen-len-totUsed-2,SEEK_END);
//     fwrite(name,1,nlen,f);
//     fwrite(data,1,len,f);
//     // while(k < nlen)
//     // {
//         // putc(name[k],f);
//         // k++;
//     // }
//     bound += nlen;
//     k=0;
//     while(k<len)
//     {
//         // putc(data[k],f);
//         k++;
//     }
//     count = count + 1;
//     return true;
// }
