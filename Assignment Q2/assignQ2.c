/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
void main()
{
    char str1[50]="Hello World";
    char str2[50]=" Welcome to C Programming";
    char str3[50]="";
    char temp;
    int i,j;

    printf("\nStrings Before Performing String Operations");
    printf("\nString 1:%s\nString 2:%s\nString 3:%s",str1,str2,str3);

    //Copying String
    printf("\n\nCopying String 1 to String 3");
    printf("\nContents of String after Copying");
    i=0;
    while(str1[i]!=NULL)
    {
        str3[i]=str1[i];
        i++;
    }
    printf("\nString 1:%s \t String 3:%s \n",str1,str3);


    //Concatenation of string
    printf("\n\nConcatenating String 2 with String 1");
   // str3[50]="";
    i=0,j=0;
    while(str1[i]!='\0')
    {
        str3[j]=str1[i];
        i++;
        j++;
    }
    i=0;
    while(str2[i]!='\0')
    {
        str3[j]=str2[i];
        i++;
        j++;
    }
    printf("\nString After Concatination:\n%s\n",str3);


    //Comparing Two Strings
    i = 0;
    printf("\nResult After Comparing String1 and String2:");
   while (str1[i] == str2[i] && str1[i] != '\0')
      i++;
   if (str1[i] == str2[i])
    printf("\nTwo Strings are Equal\n");
   else
    printf("\nTwo Strings are not Equal\n");


    //Reversing String
    i=0;
    j = strlen(str1) - 1;

    while (i < j) {
       temp = str1[i];
       str1[i] = str1[j];
       str1[j] = temp;
       i++;
       j--;
    }
    printf("\nReverse string is :%s\n", str1);
}
