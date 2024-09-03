void ls(){
    fseek(f,0,SEEK_SET);
    currbit = 8;
    si cnt = count;
    ui toi =0;
    ul ending = 2;
    ui tmp1;
    ui tmp2;
    ul tmpPos;
    byte* buffer = (byte*) malloc(sizeof(byte)*50);
    printf("\tName:\t\tsize:\n");
    while(cnt--){
        tmp1 = decode(currbit,f);
        tmp2 = decode(currbit,f);
        ending += tmp2 + tmp1;
        tmpPos = ftell(f);
        printf("\t");
        fseek(f,-ending,SEEK_END);
        fgets(buffer,tmp1+1,f);
        printf("%s ",buffer);
        fseek(f,tmpPos,SEEK_SET);
        printf("\t%d",tmp2) ;
        printf("\n");
    }
}
