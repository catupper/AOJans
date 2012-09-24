#include<stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
int nums[40];

void dfs(int x, int y, int z){
  int i;
  if(x == 0){
    int first = 0;
    for(i = 0;i < z;i++){
      if(first == 1)putchar(' ');
      printf("%d", nums[i]);
      first = 1;
    }
    puts("");
    return ;
  }
  for(i = y; i >= 1;i--){
    nums[z] = i;
    dfs(x - i, min(i, x - i), z + 1);
  }
}

int main(){
  while(1){
    int n;
    scanf("%d", &n);
    if(n == 0)return 0;
    dfs(n, n, 0);
  }
}
