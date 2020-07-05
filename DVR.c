#include <stdio.h>
#include <stdlib.h>
#define infynity 999
struct
{
    int cost;
    int via;
}routetable[10][10];
int n;

void build(int i)
{
    int j,k,nc=0;
    for(j=0;j<n;j++)
    {
        for(k=0;k<n&&j!=i;k++)
        {
            if(routetable[i][j].cost!=infynity)
                nc=routetable[i][j].cost+routetable[j][k].cost;
            if(routetable[i][k].cost>nc)
            {
                routetable[i][k].cost=nc;
                routetable[i][k].via=routetable[i][j].via;            }
        }
    }
}

void findp(int i,int j)
{
    printf("%c",'A'+i);
    if(i!=j)
    {
        printf("--->");
        findp(routetable[i][j].via,j);
    }
}

void disp(int i)
{
    int j;
    printf("Final routing table for %c\n",'A'+i);
    printf("\tDestination\tCost\tOutgoing line\n");
    printf("--------------------------------------\n");
    for(j=0;j<n;j++)
    {
        printf("\t\t%c",'A'+j);
        printf("\t%d",routetable[i][j].cost);
        printf("\t%d",routetable[i][j].via);
        printf("\n");
    }
}
 void readp()
 {
     int i,j;
     printf("Enter roouting information\n");
     for(i=0;i<n;i++)
     {
         printf("Enter routing table for %c\n",'A'+i);
         for(j=0;j<n;j++)
         {
             if(i==j)
                routetable[i][j].cost=0;
             else
             {
                 printf("--->%c:",'A'+j);
                 scanf("%d",&routetable[i][j].cost);
             }
             if(routetable[i][j].cost!=infynity)
                routetable[i][j].via=j;
             else
                routetable[i][j].via=infynity;


         }
     }
 }
int main()
{
    int src,dest,i,opt;
    printf("Enter the no of routers\n");
    scanf("%d",&n);
    readp();
    for(i=0;i<n;i++)
        build(i);
    for(i=0;i<n;i++)
        disp(i);
    do
    {
        printf("Enter source node:");
        scanf("%d",&src);
        printf("Enter dest node:");
        scanf("%d",&dest);
        findp(src,dest);
        printf("Cost of shortest path is:%d\n",routetable[src][dest].cost);
        printf("Do you want to conitnue(0/1):");
        scanf("%d",&opt);
    }while(opt);
    return 0;
}
