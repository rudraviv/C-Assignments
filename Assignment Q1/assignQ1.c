/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
#include<string.h>
int main(int argc,char *arg[])
{
       char *temp;

        temp=strtok(arg[1],",");
        while (temp != NULL)
        {
            printf("%s\n", temp);
            temp = strtok(NULL, ",");
        }
        return 0;
}
