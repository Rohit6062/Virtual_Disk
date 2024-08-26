void ls(){
    i=2;
    currbit = 8;
    si cnt = count;
    ui toi =0;
    ui ending = FILESIZE;
    ui tmp1;
    ui tmp2;
    printf("\tName:\t\tsize:\n");
    while(cnt--){
        tmp1 = decode(currbit);
        tmp2 = decode(currbit);
        ending -= tmp2;
        printf("\t");
        for(int k=ending-tmp1;k<ending;k++)printf("%c",disk[k]);
        printf("\t%d",tmp2);
        ending-=tmp1;
        printf("\n");
    }
}
