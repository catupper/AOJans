#include<stdio.h>

int main(){
  int A[5000], B[5000], i, j, a, b, ans = 0;
  scanf("%d%d", &a, &b);
  for(i = 0;i < a;i++){
    scanf("%d", A + i);
  }
  for(i = 0;i < b;i++){
    scanf("%d", B + i);
  }
  for(i = 0;i < b;i++){
    int k = 0;
    for(j = 0;j < a;j++){
      if(i + k >= b)break;
      if(B[i + k] == A[j])k++;
    }
    if(k > ans){
      ans = k;
    }
  }
  printf("%d\n", ans);
  return 0;
}
