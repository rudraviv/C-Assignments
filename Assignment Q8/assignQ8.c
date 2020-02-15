/*
Name: Rudra J. Vivarekar
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct NODE {
    char movieID[100];
    char movieName[100];
    char movieGenre[500];
    struct NODE *next;
} *head=NULL;
void byGenre();
void byName();
char genre[10][10]={"Action","Adventure","Animation","Children","Comedy","Crime","Drama","Fantasy",
              "Romance","Thriller"};
void main()
{
int ch;
FILE *data;
data = fopen("./movie.csv", "r");
/*if(data)
{
    printf("Database Connected");
}
else{
    printf("Database Not Connected");
}*/
char parsedLine[100];



while (fgets(parsedLine,sizeof(parsedLine), data) != NULL)
    {
    struct NODE *node = malloc(sizeof(struct NODE));

    char *getUser = strtok(parsedLine, ",");
    strcpy(node->movieID, getUser);

    //printf("%s\n",node->movieID);

    char *getPass = strtok(NULL, ",");
    strcpy(node->movieName, getPass);
    //printf("%s\n",node->movieName);

    char *getType = strtok(NULL, ",");
    strcpy(node->movieGenre, getType);
    //printf("%s\n",node->movieGenre);

    node->next = head;
    head = node;
}
fclose(data);
while(1)
{
        printf("\n********MENU***********");
        printf("\n1.Search Movies by name");
        printf("\n2.Search Movies by genre");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            byName();
            break;
        case 2:
            byGenre();
            break;
        case 3:
            exit(0);
            break;
        }
}


}
byGenre()
{
    int ch;
    struct NODE *curNode;
    curNode=head;
    char *tempChoice;
   // char genre[50];
    int i;
    printf("\nAvailable Genres:\n");
    for(i=1;i<=10;i++)
    {
            printf("%d\t%s\n",i,genre[i-1]);
    }
    printf("\n Enter Number of corresponding genre: ");
    scanf("%d",&ch);
    tempChoice=genre[ch-1];
    printf("%s",tempChoice);
      printf("\nMovie Found:\nID\tNAME\t\t\t\t\tGenre");
    while (curNode != NULL  )
    {
        char *p;
        p=strstr(curNode->movieGenre,tempChoice);

       if(p)
       {

           printf("\n%s\t%s \t\t%s",curNode->movieID,curNode->movieName,curNode->movieGenre);
           curNode = curNode->next;
       }
       else{
        curNode = curNode->next;
       }

    }
}
byName()
{
    char name[50];

    struct NODE *curNode;
    curNode=head;
    //printf("Enter movie name with release year e.g Skyfall (2012): ");
    printf("Enter movie name/characters: ");
    fflush(stdin);
    gets(name);
     while (curNode != NULL )
    {

        char *p;
        p=strstr(curNode->movieName,name);
        if(p)
       {

           printf("\n%s\t%s \t\t%s",curNode->movieID,curNode->movieName,curNode->movieGenre);
           curNode = curNode->next;
       }
       else{
        curNode = curNode->next;
       }

       /* if(strcmp(curNode->movieName,name)==0)
        {
            printf("\nMovie Found:\nID\tNAME\t\t\tGenre");
            printf("\n%s\t%s\t%s",curNode->movieID,curNode->movieName,curNode->movieGenre);
            return;
        }
        else{
        curNode = curNode->next;
        }*/

    }
}
