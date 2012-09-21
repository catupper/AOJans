#include<stdio.h>
#include<string.h>
int main(){
  int n, i, j, k, res = 0;
  char search[20],ring[20];
  scanf("%s", search);
  scanf("%d\n", &n);
  res = 0;
  for(i = 0;i < n;i++){
    scanf("%s", ring);
    int found = 0;
    for(j = 0;j < 10 && found == 0;j++){
      found = 1;
      for(k = 0;k < strlen(search);k++){
	if(search[k] != ring[(j + k) % 10]){
	  found = 0;
	  break;
	}
      }
    }
    if(found == 1)res++;
  }
  printf("%d\n", res);
  return 0;
}
