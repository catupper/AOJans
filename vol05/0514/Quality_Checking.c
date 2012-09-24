#include<stdio.h>

int main(){
  while(1){
    int parts[350], a, b, c, n, i;
    int check[1000][4];
    for(i = 0;i < 350;i++)parts[i] = 2;
    scanf("%d%d%d", &a, &b, &c);
    if(a == 0 && b == 0 && c == 0) return 0;
    scanf("%d", &n);
    for(i = 0;i < n;i++){
      scanf("%d%d%d%d", &check[i][0], &check[i][1], &check[i][2], &check[i][3]);
      if(check[i][3] == 1){
	parts[check[i][0]] = 1;
	parts[check[i][1]] = 1;
	parts[check[i][2]] = 1;
      }
    }
    for(i = 0;i < n;i++){
      if(check[i][3] == 0){
	if(parts[check[i][0]] * parts[check[i][1]] * parts[check[i][2]] == 2){
	  if(parts[check[i][0]] == 2)parts[check[i][0]] = 0;
	  if(parts[check[i][1]] == 2)parts[check[i][1]] = 0;
	  if(parts[check[i][2]] == 2)parts[check[i][2]] = 0;
	}
      }
    }
    for(i = 1; i <= a + b + c;i++){
      printf("%d\n", parts[i]);
    }
  }
}
