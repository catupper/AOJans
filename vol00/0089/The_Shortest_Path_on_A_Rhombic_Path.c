#include<stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int nums[100][100];

int main(){
  int row = 0,pos = 0, ans = 0, i, j;
  while(scanf("%d", &nums[row][pos]) != EOF){
    pos++;
    if(getchar() == '\n'){
      row++;
      pos = 0;
    }
  }
  row /= 2;
  row++;
  for(i = 1;i < row;i++){
    nums[i][0] += nums[i - 1][0];
    for(j = 1;j < i;j++){
      nums[i][j] += max(nums[i - 1][j - 1], nums[i - 1][j]);
    }
  }
  for(;i < row * 2 - 1;i++){
    for(j = 0;j < row;j++){
      nums[i][j] += max(nums[i - 1][j], nums[i - 1][j + 1]);
      ans = max(nums[i][j], ans);
    }
  }
  printf("%d\n", ans);
  return 0;
}
