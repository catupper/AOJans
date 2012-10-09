#include<stdio.h>

int main(){
  int a[4], b[4], i, j, hit, blow;
  while(scanf("%d%d%d%d", a, a + 1, a + 2, a + 3) != EOF){
    hit = blow = 0;
    scanf("%d%d%d%d", b, b + 1, b + 2, b + 3);
    for(i = 0;i < 4;i++){
      if(a[i] == b[i]){
	hit++;
	continue;
      }
      for(j = 0;j < 4;j++){
	if(a[i] == b[j])blow++;
      }
    }
    printf("%d %d\n", hit, blow);
  }
  return 0;
}
