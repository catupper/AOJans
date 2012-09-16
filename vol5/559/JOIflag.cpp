#include<stdio.h>
#include<string.h>
#define minn(x,y) ((x) > (y) ? (y) : (x))
int dp[2][1 << 21][2]; //positon, is lsat J  
int main(){
  int m, n;
  char flag[500];
  scanf("%d%d" ,&m ,&n);
  for (int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      scanf(" %c" ,flag + i*n + j);
   
  int filled = (1<<n)-1,u=1;
  dp[1][0][0]=1;
  for(int i = 0, x = 0; i < n*m; i++, x ^= 1){
    memset(dp[x],0,sizeof(int) << 22);
    for(int j = 0; j < 1<<n; j++){
      if(flag[i] == '?' || flag[i] == 'J'){
	dp[x][(j<<1) & filled][1]       += dp[x^1][j][0] + dp[x^1][j][1];   //JJ,OJ,IJ	 
	dp[x][(j<<1) & filled][1]       %= 100000;
      }
      if(flag[i] == '?' || flag[i] == 'O'){
	dp[x][((j<<1)+1) & filled][0] += dp[x^1][j][1];                   //JO	  
	dp[x][((j<<1)+1) & filled][0] %= 100000;
	dp[x][(j<<1) & filled][0]       += dp[x^1][j][0];                   //OO,IO
	dp[x][(j<<1) & filled][0]       %= 100000;
      }
      if((j < 1<<n-1 || i%n == 0) && (flag[i] == '?' || flag[i] == 'I')){
	dp[x][(j<<1) & filled][0]       += dp[x^1][j][0] + dp[x^1][j][1]; //OI,II,JI	  
	dp[x][(j<<1) & filled][0]       %= 100000;
      }
    }    
    if(flag[i] == '?'){
      u *= 3;
      u %= 100000;
    }
  }
  for(int i = 0; i < 1<<n ; i++){
    u-=dp[(n*m) % 2][i][0]+dp[(n*m) % 2][i][1];
    u%=100000;
  }
  printf("%d\n",(100000 + u) % 100000);
}
