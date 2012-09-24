#include<stdio.h>
#include<string.h>
int main(){
  while(1){
    int n, m, results[100], i ,j;
    memset(results, 0, sizeof(results));
    scanf("%d%d", &n, &m);
    if(n == 0 && m == 0)return 0;
    for(i = 0;i < n;i++){
      for(j = 0;j < m;j++){
	int k;
	scanf("%d", &k);
	results[j] += k;
      }
    }
    int first = 0;
    for(i = n;i >= 0;i--){
      for(j = 0;j < m;j++){
	if(results[j] == i){
	  if(first == 1)putchar(' ');
	  printf("%d",j + 1);
	  first = 1;
	}
      }
    }
    puts("");
  }
}
