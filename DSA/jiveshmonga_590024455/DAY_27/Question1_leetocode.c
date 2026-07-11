#include<stdio.h>

int compress(char* chars, int charsSize) {
int read=0;
int write=0;
while(read<charsSize)
{
    char current=chars[read];
    int count=0;

    while(read<charsSize && chars[read]==current)
    {
        read++;
        count++;
    }
    chars[write++]=current;

    if(count>1)
    {
        char num[12];
        sprintf(num,"%d",count);

        for(int i=0;num[i]!='\0';i++)
        {
            chars[write++]=num[i];
        }
    }
}    
return write;
}