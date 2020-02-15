/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
struct Acc_Holder
{
    char name[50];
    char address[50];
    char email[20];
};
struct Account
{
    int id;
    char type[10];
    double balance;
    struct Acc_Holder a;
    struct Account *next;
    struct Account *prev;
};
struct Account *head;
void add_at_first();
void display_forward();
void display_backward();
void add_at_last();
void delete_first();
void find();
void main()
{
    int ch;
    do{
    printf("\n***********MENU******************");
    printf("\n1.Add First\n2.Add Last\n3.Display Forward\n4.Display Backward\n5.Delete First\n6.Delete Last\n7.Find\n8.Exit");
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        add_at_first();
        break;
    case 2:
        add_at_last();
        break;
    case 3:
        display_forward();
        break;
    case 4:
        display_backward();
        break;
    case 5:
        delete_first();
        break;
    case 6:
        delete_last();
        break;
    case 7:
        find();
        break;
    case 8:
        exit(0);
        break;
    default:
        printf("\nEnter Valid Choice:");
        break;
    }
    }while(ch!=8);
}
void add_at_first()
{
    struct Account *ptr;
    ptr=(struct Account*)malloc(sizeof(struct Account));
    if(ptr==NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("\nEnter ID: ");
        scanf("%d",&ptr->id);
        printf("\nEnter Account Type(Saving/Current): ");
        fflush(stdin);
        gets(ptr->type);
        printf("\nEnter Name of Account Holder: ");
        gets(ptr->a.name);
        printf("\nEnter Address: ");
        gets(ptr->a.address);
        printf("\nEnter email id: ");
        gets(ptr->a.email);
        printf("\nEnter Balance: ");
        scanf("%lf",&ptr->balance);
        if(head==NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            ptr->next=head;
            ptr->prev=NULL;
            head->prev=ptr;
            head=ptr;
        }
        printf("\nData Added Successfully\n\n");
    }
}
void add_at_last()
{
    struct Account *ptr,*temp;
    ptr=(struct Account*)malloc(sizeof(struct Account));
    if(ptr==NULL)
    {
        printf("Overflow");
    }
    else
    {

        printf("\nEnter ID: ");
        scanf("%d",&ptr->id);
        printf("\nEnter Account Type(Saving/Current): ");
        fflush(stdin);
        gets(ptr->type);
        printf("\nEnter Name of Account Holder: ");
        gets(ptr->a.name);
        printf("\nEnter Address: ");
        gets(ptr->a.address);
        printf("\nEnter email id: ");
        gets(ptr->a.email);
        printf("\nEnter Balance: ");
        scanf("%lf",&ptr->balance);
        if(head==NULL)
            {
                ptr->next=NULL;
                ptr->prev=NULL;
                head=ptr;
            }
            else
            {
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->prev=temp;
                ptr->next=NULL;
            }
            printf("\nData Added Successfully\n\n");
    }

}
delete_first()
{
    struct Account *ptr;
    if(head==NULL)
    {
      printf("\nList is Empty\n\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("Data Deleted Successfully\n\n");
    }
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
        printf("Data Deleted Successfully\n\n");
    }
}
void delete_last()
{
    struct Account *temp;
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("Data Deleted Successfully\n\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
        printf("\nData deleted Successfully\n\n");
    }
}
void find()
{
    struct Account *ptr;
    int i=0,flag,ch,id;
    char name[20];
    ptr=(struct Account*)malloc(sizeof(struct Account));
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nList is Empty");

    }
    else
    {
        printf("\n1.Find By Account ID\n2.Find By Name\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter Account ID: ");
            scanf("%d",&id);
            while(ptr!=NULL)
        {
            if(ptr->id==id)
            {
                 printf("\n************************************");
                 printf("\nID: %d",ptr->id);
                 printf("\nAccount Type: %s",ptr->type);
                 printf("\nAccount Holder's Name: %s",ptr->a.name);
                 printf("\nAddress: %s",ptr->a.address);
                 printf("\nemail id: %s",ptr->a.email);
                 printf("\nEnter Balance: %.2f",ptr->balance);
                 printf("\n************************************\n\n");
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            ptr=ptr->next;
            i++;
        }
        if(flag==1)
        {
            printf("Sorry..........Record Not Found\n\n");
        }
            break;
        case 2:
            printf("\nEnter Name: ");
            fflush(stdin);
            gets(name);
            while(ptr!=NULL)
        {
            if(strcmp(ptr->a.name,name)==0)
            {
                 printf("\n************************************");
                 printf("\nID: %d",ptr->id);
                 printf("\nAccount Type: %s",ptr->type);
                 printf("\nAccount Holder's Name: %s",ptr->a.name);
                 printf("\nAddress: %s",ptr->a.address);
                 printf("\nemail id: %s",ptr->a.email);
                 printf("\nEnter Balance: %.2f",ptr->balance);
                 printf("\n************************************\n\n");
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            ptr=ptr->next;
            i++;
        }
        if(flag==1)
        {
            printf("Sorry....Record Not Found\n\n");
        }
            break;
        }


    }
}

display_forward()
{
    struct Account *ptr;
    if(head==NULL)
    {
        printf("\n\nlist is empty\n\n");
    }
    else
    {
    ptr=head;
    printf("\n!!!DISPLAYING ACCOUNT INFORMATION IN FORWARD DIRECTION!!!\n");
    while(ptr!=NULL)
    {
        printf("\n************************************");
        printf("\nID: %d",ptr->id);
        printf("\nAccount Type: %s",ptr->type);
        printf("\nAccount Holder's Name: %s",ptr->a.name);
        printf("\nAddress: %s",ptr->a.address);
        printf("\nemail id: %s",ptr->a.email);
        printf("\nEnter Balance: %.2f",ptr->balance);
        printf("\n************************************\n\n");
        ptr=ptr->next;
    }
    }
}
void display_backward()
{
     struct Account *ptr;
    if(head==NULL)
    {
        printf("\n\nlist is empty\n\n");
    }
    else
    {
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    printf("\n!!!DISPLAYING ACCOUNT INFORMATION IN BACKWARD DIRECTION!!!\n");
    while(ptr!=NULL)
    {
        printf("\n************************************");
        printf("\nID: %d",ptr->id);
        printf("\nAccount Type: %s",ptr->type);
        printf("\nAccount Holder's Name: %s",ptr->a.name);
        printf("\nAddress: %s",ptr->a.address);
        printf("\nemail id: %s",ptr->a.email);
        printf("\nEnter Balance: %.2f",ptr->balance);
        printf("\n************************************\n\n");
        ptr=ptr->prev;
    }
    }
}
