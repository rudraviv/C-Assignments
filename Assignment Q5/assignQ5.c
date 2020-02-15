/*
Name: Rudra J. Vivarekar
*/
#include <stdio.h>
#include <time.h>
typedef struct
{
    int id;
    char name[30];
    char addr[30];
    double salary;
    int dobDD,dobMM,dobYY;
    int dojDD,dojMM,dojYY;
}Employee;
int main()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    int cDate,cMonth,cYear;
    int NoE,i;
    cDate=tm.tm_mday;
    cMonth=tm.tm_mon+1;
    cYear=tm.tm_year+1900;
    float aATj;
    int mon_diff,year_diff,day_diff,totExp;
    int DDprob,MMprob,YYprob;
  //  printf("\nSystem Date is: %02d/%02d/%04d\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    Employee info[10]={};
    printf("\nEnter Number Employee: ");
    scanf("%d",&NoE);

    for(i=0;i<NoE;i++)
    {
        printf("\nEnter Employee ID:");
        scanf("%d",&info[i].id);
        printf("\nEnter Employee Name:");
        scanf("%s",info[i].name);
        printf("\nEnter Employee Address:");
        scanf("%s",info[i].addr);
        printf("\nEnter Employee Salary:");
        scanf("%lf",&info[i].salary);
        printf("\nEnter Date of Birth of Employee(DD/MM/YY)");
        scanf("%d/%d/%d",&info[i].dobDD,&info[i].dobMM,&info[i].dobYY);
        printf("\nEnter Date of Joining of Employee(DD/MM/YY)");
        scanf("%d/%d/%d",&info[i].dojDD,&info[i].dojMM,&info[i].dojYY);
    }
    printf("\nID \tName\tAge at Joining\tExperience\tprobation status");
    for(i=0;i<NoE;i++)
    {
        aATj=(float)(info[i].dojYY-info[i].dobYY);
         if(cDate < info[i].dojDD)
        {
            // borrow days from february
            if (cMonth == 3)
            {
                //  check whether year is a leap year
                if ((cYear % 4 == 0 && cYear % 100 != 0) || (cYear % 400 == 0))
                {
                    cDate += 29;
                }

                else
                {
                    cDate += 28;
                }
            }

            // borrow days from April or June or September or November
            else if (cMonth == 5 || cMonth == 7 || cMonth == 10 || cMonth == 12)
            {
            cDate += 30;
            }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
            else
            {
                cDate += 31;
            }

            cMonth = cMonth - 1;
        }

        if (cMonth < info[i].dojMM)
        {
            cMonth += 12;
            cYear -= 1;
        }


        mon_diff = cMonth - info[i].dojMM;
        year_diff =12*(cYear - info[i].dojYY);
        totExp=mon_diff+year_diff;


        DDprob=info[i].dojDD;

        if(info[i].dojMM==10||info[i].dojMM==11||info[i].dojMM==12)
        {
            MMprob=(int)(info[i].dojMM+3)-12;
            YYprob=info[i].dojYY+1;
        }
        else
        {
            MMprob=info[i].dojMM+3;
            YYprob=info[i].dojYY;
        }

        printf("\n%d\t%s\t%.2fyears\t%d months \t\t%d/%d/%d",info[i].id,info[i].name,aATj,totExp,DDprob,MMprob,YYprob);

    }


    return 0;
}
