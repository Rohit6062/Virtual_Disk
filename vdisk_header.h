#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
typedef unsigned char byte;
typedef short unsigned int si;
typedef unsigned int ui;
typedef unsigned long ul;

typedef struct diskinfo{
    FILE* f;
    byte currBit;
    int val;
    ui count;
    ui fileSize;
}diskinfo;

// si count;
// FILE* f;
// byte* disk;
// ul currByte;
// byte read;
// ui i=0;
// byte currbit=8;
// ui FILESIZE;

long decode(diskinfo*);
bool encode(diskinfo* ,unsigned long);
bool add(diskinfo* ,byte*,FILE*);
void ls(diskinfo*);
bool view(diskinfo*,ui);
bool get(diskinfo* ,byte*);
ul filesCnt(diskinfo*);
bool delete(diskinfo*,byte*);
bool del(diskinfo*,int );
long log_2(unsigned long);
ul max(ul ,ul);
byte getBitReq(ul);
void pl(long long);
long makeToget(long);
void pb(byte);
diskinfo* init(); 
void save(FILE*);
