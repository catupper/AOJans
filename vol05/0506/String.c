#include<stdio.h>
#include<string.h>

int main(){
  while(1){
    char str[100000], tmp[100000];
    int n, i, j;
    scanf("%d", &n);
    if(n == 0)return 0;
    scanf(" %s", str);
    for(i = 0;i < n;i++){
      char now = str[0];
      int cnt = 1, pos = 0;
      for(j = 1;j < strlen(str);j++){
	if(str[j] == now)cnt++;
	else{
	  int buf;
	  sprintf(tmp + pos, "%d%c%n", cnt, now, &buf);
	  pos += buf;
	  cnt = 1;
	  now = str[j];
	}
      }
      sprintf(tmp + pos, "%d%c", cnt, now);
      strcpy(str, tmp);
    }
    printf("%s\n", str);
  }
}
