  #include <stdio.h>
   int graph[10][10], visited[10], n;
   void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) {
    if (graph[v][i] == 1 && !visited[i]) {
    DFS(i);
    }
   }
  }
  int main() {
   int i, j, start;
   printf("Enter number of vertices: ");
   scanf("%d", &n);
   printf("Enter adjacency matrix:\n");
   for (i = 1; i <= n; i++) {
   for (j = 1; j <= n; j++) {
   scanf("%d", &graph[i][j]);
   }
   }
   for (i = 1; i <= n; i++)
   visited[i] = 0;
   printf("Enter starting vertex: ");
   scanf("%d", &start);
   printf("DFS Traversal: ");
   DFS(start);
   return 0;
 }


output
Enter number of vertices: 4
Enter adjacency matrix:
2 1 0 0
1 2 0 3
1 2 3 4
1 2 0 0
Enter starting vertex: 1
DFS Traversal: 1 2 