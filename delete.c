bool del(int x){
    if(x>count)return false;
    i=2;
    currbit=8;
    ui *arr1 = (ui*) calloc(sizeof(ui),count-1);
    ui *arr2 = (ui*) calloc(sizeof(ui),count-1);
    ui k =0;
    ui ending = FILESIZE;
    bool flag=false;
    ul tmp1;
    ul tmp2;
    ui tmp;
    ui bound = 0;
    while(k<count){
        tmp1 = decode(currbit);
        tmp2 = decode(currbit);
        ending-= tmp1;
        ending-= tmp2;
        if(flag){
            tmp = ending+tmp1+tmp2-1;
            int l=0;
            // while(tmp2>=ending)printf("%c", disk[tmp2--]);
            while(tmp >= ending)disk[tmp+bound] = disk[tmp],tmp--;
        }
        else if((k+1)==x){
            flag = true;
            bound = tmp1 + tmp2;
            k++;
            continue;
        }
        if(flag)arr1[k-1]=tmp1,arr2[k-1]=tmp2;
        else arr1[k]=tmp1,arr2[k]=tmp2;
        k++;
    }
    count -= 1;
    i=2;
    currbit=8;
    k=0;
    while(k < count)encode(arr1[k],currbit),encode(arr2[k],currbit),k++;
    return true;
}

bool delete(byte* name){
    ui len = strlen(name);
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
            return del(count-cnt);
        }
    }
    return false;
}
