#include<stdio.h>

char oc[] = "01235789";

void oct(int a){
  if(a == 0)return;
  oct(a / 8);
  putchar(oc[a % 8]);
}

int main(){
  int a;
  while(scanf("%d", &a)){
    if(a == 0)return 0;
    oct(a);
    puts("");
  }  
}
