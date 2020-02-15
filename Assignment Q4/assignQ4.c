/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 10
 typedef struct
    {
        int id;
        char name[30];
        double price;

    }book;
 book temp;

void mergesort(book bk[10],int i,int j)
{
	int mid;

	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(bk,i,mid);		//left recursion
		mergesort(bk,mid+1,j);	//right recursion
		merge(bk,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}
void merge(book bk[10],int i1,int j1,int i2,int j2)
{
	 book temp[10];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;

	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(bk[i].price>bk[j].price)
			temp[k++]=bk[i++];
		else
			temp[k++]=bk[j++];
	}

	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=bk[i++];

	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=bk[j++];

	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		bk[i]=temp[j];
}
int compareName(const void *fname,const void *sname)
{
    const book *s1=fname;
    const book *s2=sname;
    return strcmp(s1->name,s2->name);
}
void main()
{
   int i,n;
   book bk[10]={ {1,"Physics",200},{2,"Chemistry",20},{3,"Algebra",99.99},{4,"Geometry",900},
                 {5,"Biology",50},{6,"English",180},{7,"History",250},{8,"Civics",320},{9,"Geography",105},
                 {10,"Java",800}};
   printf("\nList of Books Without Sorting:");
   printf("\nID \tName \t\tPrice");
   for(i=0;i<10;i++)
   {
      printf("\n%d \t%s \t\t%.2f",bk[i].id,bk[i].name,bk[i].price);
   }
    //Applying Merge Sort.
    mergesort(bk,0,max-1);

    printf("\n\nList of Books in Descending order of Price: ");
    printf("\nID \tName \t\tPrice");
   for(i=0;i<10;i++)
   {
      printf("\n%d \t%s \t\t%.2f",bk[i].id,bk[i].name,bk[i].price);
   }

   printf("\n\nList of Books in Ascending order of Name: ");
   n=sizeof(bk)/sizeof(book);
   qsort(bk,n,sizeof(book),compareName);
   printf("\nID \tName \t\tPrice");
    for(i=0;i<10;i++)
   {
      printf("\n%d \t%s \t\t%.2f",bk[i].id,bk[i].name,bk[i].price);
   }
}

