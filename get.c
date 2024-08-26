bool view(int n){
    i=2;
    currbit = 8;
    if(count < n)return false;
    int tmp = n;
    int nlen=0;
    int len=0;
    int bound=0;
    while(tmp--){
        nlen = decode(currbit);
        len = decode(currbit);
        bound += nlen + len;
    }
    tmp = 0;
    while(tmp < nlen){
        printf("%c",disk[FILESIZE - bound + tmp]);
        tmp++;
    }
    printf(" \n");
    bound -= nlen;
    tmp = 0;
    while(tmp < len){
        printf("%c",disk[FILESIZE - bound + tmp]);
        tmp++;
    }
    printf(" \n");
    return true;
}

bool get(byte* name){
    ui len  = strlen(name);
    i=2;
    currbit = 8;
    ui cnt = count;
    ui ending = FILESIZE;
    ui tmp;
    while(cnt--){
        tmp = decode(currbit);
        ending-=tmp;
        ending-=decode(currbit);
        if(strncmp(disk+ending,name,len)==0){
            return view(count-cnt);
        }
    }
    return false;
}
