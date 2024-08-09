//program to read a matrix and print diagonals
#include <stdio.h>
void printMatrixDiagonals(int a[10][10], int m, int n)
{
    printf("The matrix is\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("The diagonal elements are\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                printf("%d ", a[i][j]);
    printf("\n");
}

void matrixmultiplication(int a[10][10], int b[10][10], int m, int n, int p, int q)
{
    int c[10][10];
    if (n != p)
    {
        printf("Matrix multiplication not possible\n");
        return;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    printf("The resultant matrix is\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}
void lowerdiagonal(int a[10][10], int m, int n)
{
    printf("The lower diagonal elements are\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i > j)
                printf("%d ", a[i][j]);
    printf("\n");
}
void interchangerows(int a[10][10], int m, int n)
{
    int r1,r2,temp;
    printf("Enter the rows to be interchanged\n");
    scanf("%d %d",&r1,&r2);
    for(int i=0; i<=n; i++)
    {
        temp=a[r1][r2];
        a[r1][r2]=a[r2][r1];
        a[r2][r1]=temp;

    }
    printf("The matrix after interchanging the rows is\n");
    for (int i=0; i<m;i++)
    {
        for nt((j=0;j<n;
        printf("%d ",a[i][j]);
    }
}
int main()
{
    int a[10][10], b[10][10], m, n, p, q, ch;
    printf("Enter the order of the matrix\n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printMatrixDiagonals(a, m, n);
    return 0;
    while(ch!=5):
    {
        printf("Matrix Operations\n");
        printf("1. Print Diagonal elements\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Lower Diagonal elements\n");
        printf("4.Interchange Rows");
        printf("5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printMatrixDiagonals(a,m,n):
                break;
            case 2:
                matrixmultiplication(a,b,m,n,p,q);
                break;
            case 3:
                lowerdiagonal(a,m,n);
                break;
            case 4:
                interchangerows(a,m,n);
                break;
            case 5:
                exit(0);    }
   
}
}
