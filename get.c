#include"vdisk_header.h"
// bool view(diskinfo* vdisk,ui n){
//     fseek(vdisk->f,0,SEEK_SET);
//     vdisk->currBit=8;
//     int tmp = n ,nlen=0 ,len=0 ,bound=0;
//     byte* buffer = (byte*) malloc(sizeof(byte)*50);
//     while(tmp--){
//         nlen = decode(vdisk);
//         len= decode(vdisk);
//         bound += nlen + len;
//     }
//     fseek(vdisk->f,-bound-2,SEEK_END);
//     fgets(buffer,nlen+1,vdisk->f);
//     printf("%s \n",buffer);
//     tmp = 0;
//     while(tmp < len){
//         printf("%c",getc(vdisk->f));
//         tmp++;
//     }
//     printf("\n");
//     return true;
// }

bool get(diskinfo* vdisk,byte* name){
    ui len  = strlen(name);
    byte* buffer  = (byte*) malloc(sizeof(byte)*50);
    ui cnt = vdisk->count;
    fseek(vdisk->f,0,SEEK_SET);
    vdisk->currBit=8;
    ul ending = 2;
    ui tmp,tmp2;
    ul tmpPos;
    while(cnt--){
        tmp = decode(vdisk);
        increament_bit(vdisk);
        tmp2 = decode(vdisk);
        ending = tmp2 +tmp + ending;
        if(is_bit_set(vdisk) && tmp == len){
            tmpPos = ftell(vdisk->f);
            fseek(vdisk->f,-ending,SEEK_END);
            fgets(buffer,len+1,vdisk->f);
            if(strncmp(buffer,name,len)==0){
                printf("%s \n",buffer);
                for(int i=0;i<tmp2;i++)printf("%c",getc(vdisk->f));
                increament_bit(vdisk);
                fseek(vdisk->f,tmpPos,SEEK_SET);
                return true;
            }
            fseek(vdisk->f,tmpPos,SEEK_SET);
        }
        increament_bit(vdisk);
    }
    return false;
}
