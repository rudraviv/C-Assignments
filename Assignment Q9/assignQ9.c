/*
Name: Rudra J. Vivarekar
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Inventory
{
    int id,quantity;
	char name[20];
	float price;
}Inventory;
Inventory product;
FILE *fp,*temp,*fid;

void addProduct();
//void checkWritten();
void displayAll();
void removeItem();
void findItem();
void modifyItem();

void main()
{
    createFile();
    int ch;
    do{
    printf("\n\n**********Inventory Management*******************");
    printf("\n1.Add Product\n2.Remove Product\n3.Find a Product\n4.Display All Products\n5.Modify Product Details\n6.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        addProduct();
        break;
    case 2:
        removeItem();
        break;
    case 3:
        findItem();
        break;
    case 4:
        displayAll();
        break;
    case 5:
        modifyItem();
        break;
    case 6:
        exit(0);
        break;
    }
    }while(ch!=6);
}

void createFile()
{

    fp=fopen("inventory.bin","rb+");
    //fid=fopen("ID.txt","w+");
    if(fp==NULL)                    //Opening Existing File.
    {
        printf("Creating a File");
        fp = fopen("inventory.bin", "wb+");//Creating File.
		if (fp == NULL)
        {
			printf("Can't Open File");
			exit(0);
        }
        else
        {
            printf("\nFile Created and Opened");
        }
    }
    else
    {
        printf("File Opened");
    }
}

void addProduct()
{
    rewind(fp);
	while(fread(&product, sizeof(product), 1, fp) == 1);
	 product.id=product.id+1;

    printf("\n Order Id : %d", product.id);

	printf("\n Enter Name of Item : ");
	fflush(stdin);
	gets(product.name);
	printf("\n Enter Price of Item : ");
	scanf("%f", &product.price);
	printf("\n Enter Quantity of Item : ");
	scanf("%d", &product.quantity);
	//checkWritten();

    fseek(fp,0,SEEK_END);
	fwrite(&product,sizeof(product),1, fp );
	printf("\n Item added Successfully");
}


void displayAll()
{
    rewind(fp);

    printf("\n\n********Items Details**********");
    printf("\nID \tName \tPrice \t  Quantity");
    while(fread(&product,sizeof(product),1,fp)==1)
    printf("\n%d %10s %10.2f %10d",product.id,product.name,product.price,product.quantity);
}
void removeItem()
{

    int uID,IDCount=0;
    rewind(fp);
    printf("Enter order Id: ");
    scanf("%d",&uID);
    temp=fopen("temp.bin","wb+");

    while(fread(&product,sizeof(product),1,fp)==1)
    {
       // printf("\n%d  %d",product.id,uID);//Testing
        if(product.id!=uID)
        {
            fwrite(&product,sizeof(product),1, temp );
        }
        else
        {
            IDCount=1;
        }

    }
    //printf("\nIDCount %d",IDCount);//Testing
    if(IDCount==1)
    {
        fp=fopen("inventory.bin","wb+");
        rewind(temp);
        while(0<fread(&product,sizeof(product),1,temp))
          fwrite(&product,sizeof(product),1,fp);

        printf("\nID and corresponding product has been deleted\nPlease Check List");

    }
    else{
        printf("\nID Not Found please Try Again");

    }

    fclose(temp);
    remove("temp.bin");
}


void findItem()
{
    int oID,flag=0;
    printf("\nEnter ID of product: ");
    scanf("%d",&oID);
    rewind(fp);
    while(fread(&product,sizeof(product),1,fp))
    {

        if(product.id==oID)
        {
            flag=1;
            printf("\n******Product Found********\n");
            printf("\nID \tName \tPrice \t  Quantity");
            printf("\n%d %10s %10.2f %10d",product.id,product.name,product.price,product.quantity);

        }

    }
    if(flag==0)
    {
        printf("\nOrder ID not Found please Try Again.....");
    }

}

void modifyItem()
{
    int oID,ch,flag=0;
    rewind(fp);
    printf("Enter Order ID to modify: ");
    scanf("%d",&oID);
	while (fread(&product, sizeof(product), 1, fp) == 1) {
		if (product.id == oID)
        {
            printf("\n1.Edit Name\n2.Edit Price\n3.Edit Quantity\n4.Edit All\nEnter Your Choice: ");
            scanf("%d",&ch);
            printf("\n Order Id : %d", oID);
            product.id = oID;
            switch(ch)
            {
            case 1:
                printf("\n Enter Name of Item : ");
                fflush(stdin);
                gets(product.name);
                break;
            case 2:
                printf("\n Enter Price of Item : ");
                scanf("%f", &product.price);
                break;
            case 3:
                printf("\n Enter Quantity of Item : ");
                scanf("%d", &product.quantity);
                break;
            case 4:
                printf("\n Enter Name of Item : ");
                fflush(stdin);
                gets(product.name);
                printf("\n Enter Price of Item : ");
                scanf("%f", &product.price);
                 printf("\n Enter Quantity of Item : ");
                scanf("%d", &product.quantity);
                break;
            default:
                printf("\nEnter a Valid choice");
                break;
            }
			fseek(fp,-sizeof(product),SEEK_CUR);
			fwrite(&product,sizeof(product),1,fp);
			flag=1;
			break;
		}

	}
	if(flag==0)
    {
        printf("\nOrder ID is not present....Please Try Again");
    }
    else
    {
        printf("\nItem Details Successfully Modified Please check List");
    }
}
/*void checkWritten()//Testing
{
    printf("\n%s",product.name);
}*/
