#include"base.c"
#include"encode.c"
#include"decode.c"
#include"add.c"
#include"get.c"
#include"ls.c"
#include"delete.c"
int main(){
    init();
    int inp=9;
    FILE* fp;
    int len;
    byte* fa = malloc(sizeof(byte));
    byte* name = (byte*) calloc(sizeof(byte),50);
    while(inp){
        printf("\nWelcome To Vdisk:\n\tChoose The Option.\n\t1. Add File\n\t2. Display File\n\t3. Delete file\n\t4. Show File names\n\t0. Exit\n");
        scanf("%d",&inp);
        switch(inp){
            case 0:
                printf("\n\tbye :(\n");
                save();
                break;
            case 1:
                printf("Enter file name: ");
                scanf("%s",name);
                fp = fopen(name,"r");
                if(!fp){
                    printf("Failed to open File\n");
                    break;
                }
                fseek(fp,0,SEEK_END);
                len = ftell(fp);
                fseek(fp,0,SEEK_SET);
                fa = realloc(fa, sizeof(byte)*len);
                fread(fa,sizeof(byte),len,fp);
                if(add(name,strlen(name),fa,len)==false){
                    printf("Failed to Insert file\n");
                }
                else{
                    printf("file sucessfully Inserted");
                }
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s",name);
                if(get(name)==false)printf("No such File\n");
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s",name);
                delete(name);
                break;
            case 4:
                ls();
                break;
            default:
                printf("Please choose a valid Option !!!\n");
                break;
        }
    }
    return 0;
}

