#include<stdio.h>
int sum (int*arr,int arrsize){
    int  a=0;
    for(int i=0;i<arrsize;i++){
        a=a+arr[i];
    }
    return a;

}