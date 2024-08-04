#include<stdio.h>
int main()
{ int cost[10 ][10],n;
  
  int kruskal();
  
  printf("Enter the number of node");
  scanf("%d",&n);
  printf("Enter the cost matrix");
  for(int i=0;i<n;i++)
   for(int j=0;i<n;j++)
   {
    scanf("%d",&cost[i][j]);
    if(cost[i][j]==0)
    cost[i][j]=999;
   }
   kruskal(n);

}
int kruskal(n)
{
    int a=0,b=0,u=0,v=0;
    int i,j,ne=1,min,mincost=0;
    printf("The edges of minimum cost spanning tree are");
    while(ne<n)
    {
        for(i=1,min<999;i<=n;i++)
         for(j=1;j<=n;j++)
          if(cost[i][j]<min)
          {
            min=cost[i][j];
            a=u=i;
            b=v=j;

          }
          u=find(u);
          v=find(v);
          if(u!v)
          {
            uni(u,v);
            ne++;
            printf("edge%d,%d=%d",a,b,min);

          }
          cost[a][b]=cost[b][a]=999;

        

    }
}
int find(int i)
{
    while(parent[i]>0)
          i=parent[i];
    return i;
    
}
void uni(int i,int j)
{
    parent[j]=i;
}