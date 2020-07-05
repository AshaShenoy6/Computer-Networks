#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j,k=0;
   int flag=1,div[20],g[20],r[20],a[20],m,n;
   printf("Enter deg of gen\n");
   scanf("%d",&n);
   printf("Enter the gen\n");
   for(i=0;i<=n;i++)
    scanf("%d",&g[i]);
   printf("Enter deg of frame\n");
   scanf("%d",&m);
   printf("Enter the frame\n");
   for(i=0;i<=m;i++)
    scanf("%d",&a[i]);
   for(i=m+1;i<=m+n;i++)
    a[i]=0;
   for(j=0;j<=n;j++)
    r[j]=a[j];
   for(i=n;i<=m+n;i++)
   {
       if(i>n)
       {
           for(j=0;j<n;j++)
            r[j]=r[j+1];
           r[j]=a[i];
       }
       if(r[0])
        div[k++]=1;
       else
       {
           div[k++]=0;
           continue;
       }
       for(j=0;j<=n;j++)
        r[j]=r[j]^g[j];
   }
   printf("Quotient is:\n");
   for(j=0;j<k;j++)
    printf("%d",div[j]);
   printf("\nRemainder is:\n");
   for(i=1;i<=n;i++)
    printf("%d",r[i]);
   printf("\nTransmitted frame is:\n");
   for(i=m+1,j=1;i<=m+n;i++,j++)
    a[i]=r[j];
   for(i=0;i<=m+n;i++)
    printf("%d",a[i]);
   printf("\n");
   printf("Enter the degree of the frame:\n");
   scanf("%d",&m);
   printf("Enter the frame:\n");
   for(i=0;i<=m;i++)
    scanf("%d",&a[i]);
   for(j=0;j<=n;j++)
    r[j]=a[j];
   k=0;
   for(i=n;i<=m;i++)
   {
       if(i>n)
       {
           for(j=0;j<n;j++)
            r[j]=r[j+1];
           r[j]=a[i];
       }
       if(r[0])
        div[k++]=1;
       else
       {
           div[k++]=0;
           continue;
       }
       for(j=0;j<=n;j
       ++)
        r[j]=r[j]^g[j];

   }
   printf("Quotient is:\n");
   for(j=0;j<k;j++)
    printf("%d",div[j]);
   printf("\nRemainder is:\n");
   for(i=1;i<=n;i++)
    printf("%d",r[i]);
    for(i=1;i<=n;i++)
    {
        if(r[i])
            flag=0;
    }
    if(flag)
        printf("No error\n");
    else
        printf("Error\n");
    return 0;


}
