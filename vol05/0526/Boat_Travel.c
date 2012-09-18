#include<stdio.h>
#define INF (1<<25)
#define minn(x,y) ((x)<(y)?(x):(y))

int main(){
  while(1){
    int n, k, i, j, l;
    scanf("%d %d", &n, &k);
    if(n == 0 && k == 0){
      return 0;
    }
    int dist[n][n];
    for(i = 0;i < n;i++){
      for(j = 0;j < n;j++){
	if(i == j){
	  dist[i][j] = 0;
	}
	else{
	  dist[i][j] = INF;
	}
      }
    }
    
    for(i = 0;i < k;i++){
      int mode;
      scanf("%d", &mode);
      if(mode == 0){
	int a, b;
	scanf("%d%d", &a, &b);
	a--;b--;
	if(dist[a][b] == INF){
	  printf("-1\n");
	}
	else{
	  printf("%d\n", dist[a][b]);
	}
      }
      else{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--;b--;
	dist[a][b] = minn(dist[a][b], c);
	dist[b][a] = dist[a][b];
	for(j = 0;j < n;j++){
	  for(l = 0;l < n;l++){
	    dist[j][l] = minn(dist[j][l], dist[j][a] + dist[b][l] + c);
	    dist[l][j] = dist[j][l];
	  }
	}
      }
    }
  }
}
