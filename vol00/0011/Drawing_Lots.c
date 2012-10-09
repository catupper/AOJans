#include<stdio.h>

void swap(int* a, int* b){
  int l = *a;
  *a = *b;
  *b = l;
}

int main(){
  int w, n, a, b, bows[31], i;
  for(i = 0;i <= 31;i++)
    bows[i] = i;
  scanf("%d", &w);
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d,%d", &a, &b);
    swap(bows + a, bows + b);
  }
  for(i = 1;i <= w;i++){
    printf("%d\n", bows[i]);
  }
  return 0;
}
