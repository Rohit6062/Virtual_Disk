#include"base.c"
#include"encode.c"
#include"decode.c"
#include"add.c"
#include"get.c"
#include"ls.c"
#include"filescnt.c"
// #include"delete.c"

// int main(){
//     init();
//     long k;
//     currbit = 8;
    // for(int i=0;i<64;i++)encode(f,(long)pow(2,i),currbit);
    
    // fseek(f,0,SEEK_SET);
    // currbit=8;
    // for(int i=0;i<64;i++)k = decode(currbit,f),printf("k = %ld\n", k);;
    // currbit=8;
    // add("name.txt",strlen("name.txt"),"Have you finished eating your apple.",strlen("Have you finished eating your apple.")),add("name.txt",strlen("name.txt"),"Have you finished eating your apple.",strlen("Have you finished eating your apple.")),add("name.txt",strlen("name.txt"),"Have you finished eating your apple.",strlen("Have you finished eating your apple."));
    // printf("get(name.txt) = %d\n", get("name.txt"));
    // ls();
    // save();
// }
//
//
int main(){
    init();
    count = filesCnt(f);
    printf("count = %d\n", count);
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
                if(add(name,fp)==false){
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
                // delete(name);
                break;
            case 4:
                ls();
                break;
            default:
                printf("Please choose a valid Option !!!\n");
                break;
        }
        fflush(NULL);
    }
    return 0;
}

