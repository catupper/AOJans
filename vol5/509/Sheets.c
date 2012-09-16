#include<stdio.h>
#include<string.h>
int menseki,gaishuu, n, r, i, j;
int sheet[10007][10007];
int main(){
  while(1){
    scanf("%d%d",&n,&r);
    if(n==0 && r==0)return 0;
    memset(sheet,0,sizeof(sheet));
    menseki=gaishuu=0;
    for(i = 0;i < n;i++){
      int a, b, c, d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      sheet[a][b]+=1;
      sheet[c][b]-=1;
      sheet[a][d]-=1;
      sheet[c][d]+=1;
    }
    for(i = 0;i < 10007;i++){
      for(j = 1;j< 10007;j++){
	sheet[i][j]+=sheet[i][j-1];
      }
    }
    for(j = 0;j < 10007;j++){
      for(i = 1;i < 10007;i++){
	sheet[i][j]+=sheet[i-1][j];
      }
    }
    for(i = 0;i < 10007;i++){
      for(j = 0;j < 10007;j++){
	if(sheet[i][j]>0){
	  menseki++;
	  if(i==0 || sheet[i - 1][j] == 0)gaishuu++;
	  if(i==10006 || sheet[i + 1][j] == 0)gaishuu++;
	  if(j==0 || sheet[i][j - 1] == 0)gaishuu++;
	  if(j==10006 || sheet[i][j + 1] == 0)gaishuu++;
	}
      }
    }
    printf("%d\n",menseki);
    if(r==2){
      printf("%d\n",gaishuu);
    }
  }
}


