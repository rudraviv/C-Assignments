/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>

void main()
{
    int i,ch,count,chkind[10]={0};
    signed int arr[10]={0};
    int ind,num,delNum;
    int flag=0, max=0,loc=0,sum=0,min=0;
    char choice;
   do
    {
     printf("\n*******MENU**********\n");
     printf("1.Add a number\n2.delete a number\n3.Find Maximum Number\n4.Minimum of available numbers\n5.sum of all available numbers \n6.Exit");
     printf("\nEnter Your Choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
            l2:count=0;
            printf("\nYou can add numbers at these indexes:");//showing empty blocks
            for(i=0;i<10;i++)
            {
                if(arr[i]==0)
                {
                    chkind[i]=i;
                    printf("%d  ",i);
                }
                else
                {
                count++;
                }

            }
            if(count==10)//checking weather array is full/empty
            {
                printf("\nSorry....Array is full");
                break;
            }
          l1:  printf("\nEnter a valid index and a valid number: ");
            scanf("%d %d",&ind,&num);
            if(num<=0)   //checking for positive number(0 is neutral number).
            {
                printf("\nPlease Enter a Number Greater than 0\n");
                goto l1;
            }

               if(ind>=0&&ind<=9)
               {
                   flag=1;
               }

            if(flag)
            {
                arr[ind]=num;
                flag=0;
            }
            else
            {
                printf("\nEntered Invalid index.\nplease Enter Index between 0 to 9");

                goto l1;
            }
            printf("\nContents of array after adding a number: ");
            for(i=0;i<10;i++)
            {
                printf("%d  ",arr[i]);
            }
            printf("\n\n");

            break;
           case 2:
               count=0;
            printf("\nAvailable indexes: ");
            for(i=0;i<10;i++)
            {
                if(arr[i]>0)
                {
                    printf("%d ",chkind[i]);
                }
            }
            printf("\nNumbers: ");
            for(i=0;i<10;i++)
            {

                if(arr[i]==0)
                {
                    count++;
                }
                else
                {

                    printf("%d ",arr[i]);
                }
            }
            if(count==10)
            {
                printf("\n\nArray is Empty\nAdd Positive Numbers to Array\n");
            }
            else
            {
               printf("\nEnter an index of a number to delete:");
                scanf("%d",&ind);
                delNum=arr[ind];
                arr[ind]=0;
                printf("\nContents of array after deleting %d are: ",delNum);
                for(i=0;i<10;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n\n");
            }
            break;
            case 3:
                for(i=0;i<10;i++)
                {

                    if(arr[i]==0)
                    {
                        count++;
                    }
                }
                if(count==10)
                {
                    printf("\n\nArray is Empty\nAdd Positive Numbers to Array\n");
                }
                else
                {
                    max=arr[0];
                    for(i=0;i<10;i++)
                    {
                        if(arr[i]>max)
                        {
                            max=arr[i];
                            loc=i;
                        }
                    }
                    printf("\n%d is maximum number located at %dth index(indexing start from 0)\n",max,loc);
                }
                break;
            case 4:
                for(i=0;i<10;i++)
                {

                    if(arr[i]==0)
                    {
                        count++;
                    }
                }
                if(count==10)
                {
                    printf("\n\nArray is Empty\nAdd Positive Numbers to Array\n");
                }
                else
                {
                    min=arr[0];
                    for(i=0;i<10;i++)
                    {
                        if(arr[i]<min&&arr[i]!=0)
                        {
                            min=arr[i];
                            loc=i;
                        }
                    }
                    printf("\n%d is minimum number located at %dth index(indexing start from 0)\n",min,loc);
                }
                break;

            case 5:
                for(i=0;i<10;i++)
                {

                    if(arr[i]==0)
                    {
                        count++;
                    }
                }
                if(count==10)
                {
                    printf("\n\nArray is Empty\nAdd Positive Numbers to Array\n");
                }
                else
                {
                    for(i=0;i<10;i++)
                    {
                        sum=sum+arr[i];
                    }
                    printf("\nSum of all available numbers from array:%d \n",sum);
                }
                break;
     }

    }while(ch!=6);
}
