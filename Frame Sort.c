#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#define datasz 3

struct frame
{
    int snum;
    char data[datasz+1];
};


time_t t;
int nop;

void divide(char *msg)
{
    int msglen,i,j;
    msglen=strlen(msg);
    nop=msglen/datasz;
    if((msglen%datasz)!=0)
        nop++;
     struct frame fr[nop];
    for(i=0;i<nop;i++)
    {
        fr[i].snum=i+1;
        for(j=0;j<datasz&& *msg!='\0';j++,msg++)
        {
            fr[i].data[j]=*msg;
        }
        fr[i].data[j]='\0';
    }
    printf("The message has been divided as foll:\n");
    printf("\nPacket.No\tData\n");
    for(i=0;i<nop;i++)
        printf("%d\t\t%s\n",fr[i].snum,fr[i].data);
    shuffle(fr);
    receive(fr);


}
void shuffle(struct frame fr[])
{
    int i,j;

    srand(time(&t));
    for(i=0;i<nop;i++)
    {
        j=rand()%nop;
        swap(&fr[i],&fr[j]);
    }
}
void swap(struct frame *a,struct frame *b)
{
    struct frame temp=*a;
    *a=*b;
    *b=temp;
}

void receive(struct frame fr[])
{
    int i,j;
    struct frame temp;
    printf("Packets received in the following order\n");
    for(i=0;i<nop;i++)
        printf("%d\t",fr[i].snum);
    for(i=0;i<nop;i++)
    {
        for(j=0;j<nop-1;j++)
        {
        if(fr[j].snum>fr[j+1].snum)
                {
                    temp=fr[j];
                    fr[j]=fr[j+1];
                    fr[j+1]=temp;
                }
        }

         }
         printf("Packets after sorting\n");
         for(i=0;i<nop;i++)
            printf("%d\t",fr[i].snum);
         printf("Message in order after sorting\n");
         for(i=0;i<nop;i++)
            printf("%s",fr[i].data);
}
int main()
{
    char msg[50];
    int noop;
    printf("Enter msg:\n");
    scanf("%[^\n]",msg);
    divide(msg);

    return 0;

}
