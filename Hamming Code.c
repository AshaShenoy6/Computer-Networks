#include <stdio.h>
#include <stdlib.h>
#define maxsz 50
int data[maxsz],temp[maxsz];
int power(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p=p*2;
    return p;
}
int findp(int k,int r)
{
    int n,i,j,errsum=0,cones;
    n=j=1;
    while(n<power(r))
    {
        i=n;
        cones=0;
        while(i<=(k+r))
        {
            for(j=0;j<n;j++)
            {
                if(temp[i+j]==1)
                    cones++;
            }
            i=i+2*n;
        }
        if((cones%2)!=0)
        {
            temp[n]=1;
            errsum=errsum+n;
        }
        else
          temp[n]=0;
        n=n*2;

    }
        return errsum;

}int hc(int k)
{
    int i,j,d=0;
    int r=1;
    while(k>power(r)-r-1)
        r++;
    j=k;
    for(i=1;i<=(k+r);i++)
    {
        if(i==power(d))
        {
            temp[i]=0;
            d++;

    }
    else
            temp[i]=data[j--];

}
return r;
}
int check(int errpos,int r)
{
    int i;
    for(i=1;i<power(r);i=i*2)
    {
        if(errpos==i)
            return 1;

    }
    return 0;
}

int main()
{
    int k,r,errpos,i;
    printf("Enter no of databits\n");
    scanf("%d",&k);
    printf("Enter data\n");
    for(i=1;i<=k;i++)
        scanf("%d",&data[i]);
    r=hc(k);
    printf("NO of parity bits=%d\n",r);
    findp(k,r);
    printf("Hamming code is:\n");
    for(i=1;i<=(k+r);i++)
        printf("%4d",temp[i]);
    printf("Enter receieved data\n");
    for(i=1;i<=(k+r);i++)
        scanf("%d",&temp[i]);
     errpos=findp(k,r);
     if(errpos!=0)
     {
         if(check(errpos,r))
            printf("Parity bit P%d is corrupted,data is fine\n",errpos);
         else
         {
             printf("Data bit D%d is corrupted\n",errpos);
             temp[errpos]=!temp[errpos];
             printf("Correceted\n");
             for(i=1;i<=(k+r);i++)
                  printf("%4d",temp[i]);

         }
     }
     else
        printf("No error\n");
     return 0;
}
