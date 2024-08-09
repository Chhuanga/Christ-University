//program on Pointers

#include <stdio.h>

void main()
{
    int a[10];
    int *p;
    for (int i=0;i<10;i++)
    {
        printf("Enter the value of a[%d]: ",i);
        scanf("%d",&a[i]);
    }

    p=a;
    for (int i=0;i<10;i++)
    {
        printf("The value of a[%d] is %d\n",i,*(p+i));
    }
}