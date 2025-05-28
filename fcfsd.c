#include<stdio.h>
#include<stdlib.h>
void sort(int r[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(r[j]>r[j+1])
            {
                int temp=r[j];
                r[j+1]=r[j];
                r[j]=temp;
            }
        }
    }
}
void main()
{
    int k=0,thead=0,i,chead,size,n;
    printf("Enter the no of request\n");
    scanf("%d",&n);
    int r[n],order[n+1];
    printf("Enter the requests\n");
    for(i=0;i<n;i++)
    {
        printf("Enter request %d",i+1);
        scanf("%d",&r[i]);
    }
    printf("Enter size of cylinder\n");
    scanf("%d",&size);
    printf("Enter current head position\n");
    scanf("%d",&chead);
    
    order[k++]=chead;
    for(i=0;i<n;i++)
    {
        order[k++]=r[i];
        thead+=abs(chead-r[i]);
        chead=r[i];
    }
    printf("Order\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t",order[i]);
    }
    printf("\n");
    printf("Total head movement %d",thead);
}