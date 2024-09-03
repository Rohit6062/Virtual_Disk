bool view(int n){
    fseek(f,0,SEEK_SET);
    currbit = 8;
    if(count < n)return false;
    int tmp = n;
    int nlen=0;
    int len=0;
    int bound=0;
    while(tmp--){
        nlen = decode(currbit,f);
        len = decode(currbit,f);
        bound += nlen + len;
    }
    tmp = 0;
    fseek(f,-bound-2,SEEK_END);
    while(tmp < nlen){
        printf("%c",getc(f));
        tmp++;
    }
    printf(" \n");
    bound -= nlen;
    tmp = 0;
    while(tmp < len){
        printf("%c",getc(f));
        tmp++;
    }
    printf(" \n");
    return true;
}

bool get(byte* name){
    ui len  = strlen(name);
    byte* buffer  = (byte*) malloc(sizeof(byte)*50);
    fseek(f,0,SEEK_SET);
    currbit = 8;
    ui cnt = count;
    ul ending = 2;
    ui tmp;
    ul tmpPos;
    while(cnt--){
        tmp = decode(currbit,f);
        ending+=tmp;
        ending+=decode(currbit,f);
        if(tmp == len){
            tmpPos = ftell(f);
            fseek(f,-ending,SEEK_END);
            fgets(buffer,len+1,f);
            if(strncmp(buffer,name,len)==0)return view(count-cnt);
            fseek(f,tmpPos,SEEK_SET);
        }
    }
    return false;
}
