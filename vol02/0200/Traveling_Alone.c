#include<stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define INF (1<<28)
int n, m, a, b, cost, time, costs[105][106], times[104][103], p, q, r, i, j, k;

int main(){
  while(1){
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    for(i = 1;i <= m;i++){
      for(j = 1;j <= m;j++){
	times[i][j] = INF;
	costs[i][j] = INF;
      }
    }
    for(i = 0;i < n;i++){
      scanf("%d%d%d%d", &a, &b, &cost, &time);
      costs[a][b] = costs[b][a] = cost;
      times[a][b] = times[b][a] = time;
    }
    for(k = 1;k <= m;k++){
      for(i = 1;i <= m;i++){
	for(j = 1;j <= m;j++){
	  costs[i][j] = costs[j][i] = min(costs[i][j], costs[i][k] + costs[k][j]);
	  times[i][j] = times[j][i] = min(times[i][j], times[i][k] + times[k][j]);
	}
      }
    }
    
    scanf("%d", &k);
    for(i = 0;i < k;i++){
      scanf("%d%d%d", &p, &q, &r);
      if(r == 0){
	printf("%d\n", costs[p][q]);
      }
      if(r == 1){
	printf("%d\n", times[p][q]);
      }
    }
  }
}
