#include<stdio.h>
#include<string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int main(){
  char str1[4001], str2[4001];
  int i, j, k;
  while(scanf("%s %s", str1, str2) != EOF){
    int res = 0;
    for(i = 0;i < strlen(str1);i++){
      int x = 0;
      for(k = 0;i + k < strlen(str1) && k < strlen(str2);k++){
	if(str1[i + k] == str2[k])x++;
	else x = 0;
	res = max(res, x);
      }
    }

    for(i = 0;i < strlen(str2);i++){
      int x = 0;
      for(k = 0;k < strlen(str1) && i + k < strlen(str2);k++){
	if(str1[k] == str2[i + k])x++;
	else x = 0;
	res = max(res, x);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
