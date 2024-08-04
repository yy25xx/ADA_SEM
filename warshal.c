#include<stdio.h>
#include<stdlib.h>
int a[10][10],d[10][10],n;


void path()
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)

            {
                if ((d[i][j])||(d[i][k]&&d[k][j])) 
                {
                d[i][j]=1;
                }

                
            }
        }
    }
}
int main()
{
    int i,j;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    printf("Enter the adjacent matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j];
        }
    }
    path();
    printf("The shortest path is");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
}