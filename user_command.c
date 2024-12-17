#include"vdisk_header.h"
void err(){
    printf("Command Not Found!\n");
}
void accept(diskinfo* vdisk, byte* cmd){
    printf("USER: ");
    char* name;
    char* buffer = (char*) malloc(sizeof(char)*1000);
    fgets(buffer,1000,stdin);
    char *token = strtok(buffer," ");
    switch(strlen(token)){
        case 3:
            if(!strcmp(token,"ls\n"))ls(vdisk);
            else if(!strcmp("cat",token)){
                token = strtok(NULL," ");
                while(token){
                    byte name_len = (byte) strlen(token);
                    if(token[name_len-1]==10)token[name_len-1]='\0';
                    if(get(vdisk,token)==false)printf("No such File\n");
                    token = strtok(NULL," ");
                }
            }
            else err(); 
            break;
        case 5:
            if(strtok(NULL," ")!=NULL)err();
            else if(!strcmp("exit\n",token))*cmd=0;
            else err();
            break;
        case 6:
            char* name = strtok(NULL," ");
            if(!name)err();
            else if(!strcmp("insert",token)){
                FILE* fp = fopen(name,"r");
                if(!fp)printf("No such File\n");
                else if(add(vdisk,name,fp)==false)printf("Failed to Insert file\n");
                else printf("File inserted succesfully!");
            }
            else if(!strcmp("remove",token)){
                printf("delete\n");
            }
            else err();
            break;
        default:
            err();
    }
}
