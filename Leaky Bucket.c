#include <stdio.h>
#include <stdlib.h>
#define bsize 250
#define orate 25

struct
{
    int arrtime;
    int weight;
}packet[15];

int n;
void readp(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time of %d\n",i+1);
        scanf("%d",&packet[i].arrtime);
        printf("Enter wegiht of packet %d\n",i+1);
        scanf("%d",&packet[i].weight);

    }
}
void lb()
{
    int excess=bsize;
    int j=0,rem=0,i;
    for(i=0;i<=30;i++)
    {
        if(packet[j].arrtime==i)
        {
            if(packet[j].weight<=excess)
            {
                excess=excess-packet[j].weight;
                rem=rem+packet[j].weight;
                printf("AT time=%d packet %d inserted\n",i,j+1);
                printf("Remaining space innbulet=%d\n",excess);
                j=j+1;
            }
            else
            {printf("AT time=%d packet %d discarded",i,j+1);
            j=j+1;

            }
        }
        if((i%5)==0)
        {
            if(rem>=orate)
            {
                rem=rem-orate;
                excess=excess+orate;
                printf("At time=%d 25kbytes transferred from bucket\n",i);
                printf("Remaianing bucket size=%d\n",excess);

            }
            else if(rem>0)
            {
                excess=excess+rem;
              printf("At time=%d %dkbytes transferred from bucket\n",i,rem);
              printf("Remaianing bucket size=%d\n",excess);
              rem=0;


            }
        }
    }
    while(rem!=0)
    {
        if(rem<orate)
        {
            excess=excess+rem;
            printf("At time=%d %d kbytes transferred\n",i++,rem);
            printf("Remaianing bucket size=%d\n",excess);
            break;
        }
        rem=rem-orate;
        excess=excess+orate;
        printf("At time=%d %d kbytes transferred\n",i++,orate);
            printf("Remaianing bucket size=%d\n",excess);

    }
    printf("Bucket empty\n");
}
int main()
{
    printf("Enter no of packets\n");
    scanf("%d",&n);
    readp(n);
    lb();
    return 0;
}
