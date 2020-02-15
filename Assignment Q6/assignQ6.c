/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int rollno;
    char studentName[100];
    char subject[6][500];
    int marks[6];
    int std;
    struct Node *next;
}*front=NULL,*rear=NULL;
void insert();
void display();
void deletion();
void main()
{
    int ch;

    do
    {
        printf("\n*************MENU******************");
        printf("\n1.Push\n2.Display\n3.Pop\n4.Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            deletion();
            break;
        case 4:
            break;
        }

    }while(ch!=4);
}
void insert()
{
    int i;
    struct Node *nNode;
    nNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter Student Information");
    printf("\nEnter roll no: ");
    scanf("%d",&nNode->rollno);
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(nNode->studentName);
    printf("\nEnter Standard(in number):");
    scanf("%d",&nNode->std);
    printf("\nEnter 6 subject names and their marks:\n");
    fflush(stdin);
    for(i=0;i<6;i++)
    {
        scanf("%s ",nNode->subject[i]);
        scanf("%d",&nNode->marks[i]);
    }
     if (front == NULL) {
      front = rear = nNode;
   }
   else {
      // next of rear is front in circular queue
      rear->next = nNode;
      rear = nNode;
   }
   rear->next = front;
    printf("\nInsertion is Success!!!\n");
}
void deletion()
{
    int element;
    if(front==NULL)
    {
        printf("Queue is Empty");
    }
    else if(front==rear)
    {
        free(front);
        front=rear=NULL;
    }
    else{
        struct Node *ptr=front;
        front=front->next;
        rear->next=front;
        free(ptr);
    }
}
void display()
{

int i=0;
  struct Node *ptr;
  ptr=front;
  printf("\nRollNo\tName\tstandard\tSubjects\tMarks\n");
  if(front == NULL)
  {
      printf("\nQueue is Empty!!!\n");
      return;
  }

  do{
    printf("\n%d\t%s\t%d",ptr->rollno,ptr->studentName,ptr->std);
    printf("\t\t%s \t\t%d\n\t",ptr->subject[i],ptr->marks[i]);
    for(i=1;i<6;i++)
    {
      printf("\t\t\t%s \t\t%d",ptr->subject[i],ptr->marks[i]);
      printf("\n\t");
    }
    ptr=ptr->next;
  }while(ptr!=front);
}
