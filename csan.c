#include<stdio.h>
#include<stdlib.h>
int r[20],order[20];
void sort(int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(r[j]>r[j+1])
            {
                int temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
}
void main()
{
    int pos,t,k=0,i,n,size,chead,thead=0,ltrack;
    printf("Enter the no of requests\n");
    scanf("%d",&n);
    printf("Enter requests\n");
    for(i=0;i<n;i++)
    {
        printf("Enter request %d\n",i+1);
        scanf("%d",&r[i]);
    }
    printf("Enter the current head position\n");
    scanf("%d",&chead);
    printf("Enter the size of cylinder \n");
    scanf("%d",&size);

    ltrack=size-1;
    order[k++]=chead;
    r[n]=chead;
    r[n+1]=ltrack;//total num of request become n+3
    r[n+2]=0;
    sort(n+3);
    for(i=0;i<n+3;i++)
    {
        if(r[i]==chead)
        {pos=i;//return the position of chead in the sorted requests
        break;}
    }
    for(i=pos+1;i<n+3;i++)
    {
        order[k++]=r[i];
        thead+=abs(chead-r[i]);
        chead=r[i];
    }
    for ( i = 0; i<pos; i++)
    {
        order[k++]=r[i];
        thead+=abs(chead-r[i]);
        chead=r[i];
    }
    
    printf("Order\n");
    for(i=0;i<k;i++)//coz there is n+1 +1 i/p from 199
    {
        printf("%d\t",order[i]);
    }
    printf("\n");
    printf("Total head  movement %d\n",thead);
}