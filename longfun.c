#include<stdio.h>
#include<stdlib.h>
long makeToget(long x){
    long output =0;
    while(x--)output = (output << 1) | 1;
    return output;
}

long* lshift(long* l,int n,long x){
    if(x>=64){
        for(int i=0;i<n-1;i++){
            l[i]  = l[i+1];
        }
        l[n-1]=0;
        long* output = lshift(l,n,x-64);
        return output;
    }
    long* output = (long*) calloc(n,sizeof(long));
    long tand = makeToget(x) << (64-x);
    long tor = 0;
    long tmp = 0;
    for(int i=n-1;i>-1;i--){
        tmp  = tand & l[i];
        output[i] = (l[i] << x) | tor ;
        tor  = tmp >> (64-x);
    }
    return output;
}

long* rshift(long* l,int n,long x){
    if(x>=64){
        for(int i=n-1;i>0;i--){
            l[i]  = l[i-1];
        }
        l[0]=0;
        long* output = rshift(l,n,x-64);
        return output;
    }
    long* output = (long*) calloc(n,sizeof(long));
    long tand = makeToget(x);
    long tor = 0;
    long tmp = 0;
    for(int i=0;i<n;i++){
        tmp  = tand & l[i];
        output[i] = (l[i] >> x) | tor ;
        tor  = tmp << (64-x);
    }
    return output;
}

long* band(long* a, int n,long* b){
    long* output = (long*)malloc(sizeof(long)*n);
    for(int i=0;i<n;i++){
        output[i] = a[i] & b[i];
    }
    return output;
}
long* bor(long* a, int n,long* b){
    long* output = (long*)malloc(sizeof(long)*n);
    for(int i=0;i<n;i++){
        output[i] = a[i] | b[i];
    }
    return output;
}


