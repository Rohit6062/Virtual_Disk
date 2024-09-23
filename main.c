#include"vdisk_header.h"
int main(){
    diskinfo* vdisk = init(); 
    // printf("count = %d\n", vdisk->count);
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
                save(vdisk->f);
                // fclose(f);
                break;
            case 1:
                printf("Enter file name: ");
                scanf("%s",name);
                fp = fopen(name,"r");
                if(!fp){
                    printf("Failed to open File\n");
                    break;
                }
                if(add(vdisk,name,fp)==false){
                    printf("Failed to Insert file\n");
                }
                else{
                    printf("file sucessfully Inserted");
                }
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s",name);
                if(get(vdisk,name)==false)printf("No such File\n");
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s",name);
                // delete(name);
                break;
            case 4:
                ls(vdisk);
                break;
            default:
                printf("Please choose a valid Option !!!\n");
                break;
        }
        fflush(NULL);
    }
    // for(int i=1;i<10000000;i++)
        // printf("encode %d %d\n",30770220, encode(vdisk,3077020)),
        // printf("encode %d %d\n",30770220, encode(vdisk,3077020));

        // fseek(vdisk->f,0,SEEK_SET),
        // vdisk->currBit = 8;
    // for(int i=0;i<10000000;i++)
        // printf("decode(vdisk) = %ld\n", decode(vdisk)),
        // printf("decode(vdisk) = %ld\n", decode(vdisk));
    return 0;
}
