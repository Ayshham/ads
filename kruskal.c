   #include<stdio.h>
   int main(){
       int n;
       printf("enter number of vertices: ");
       scanf("%d",&n);
       int cost[10][10],parent[10];
       int a,b,u,v,min,edges=0,total=0;
       printf("enter cost adjacency matrix(0=no edge):\n");
       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              scanf("%d",&cost[i][j]);
      for(int i=0;i<n;i++)
          parent[i]=i;
      printf("\nedges selected:\n");
      while(edges<n-1){
          min=9999;
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
                  if(cost[i][j]!=0 && cost[i][j]<min){
                      min=cost[i][j];
                      a=i;
                      b=j;
                  }
          u=a;
          while(parent[u]!=u) u=parent[u];
          v=b;
          while(parent[v]!=v) v=parent[v];
          if(u!=v){
              printf("%d=> %d(cost=%d)\n",a,b,min);
              parent[u]=v;
              total+=min;
              edges++;
          }
          cost[a][b]=cost[b][a]=9999;
      }
      printf("\ntotal minimum cost=%d\n",total);
      return 0;
  }
   

output
enter number of vertices: 4
enter cost adjacency matrix(0=no edge):
0 10 5 6
3 5 4 6
1 0 12 3
2 34 5 1

edges selected:
2=> 0(cost=1)
3=> 0(cost=2)
1=> 0(cost=3)

total minimum cost=6




