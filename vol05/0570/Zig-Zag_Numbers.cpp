#include<cstdio>
#include<cstring>

char a[505], b[505];
int dp[505][10][500][2][3];
int m, lena, lenb, ans = 10000;

int solvea(int keta, int last, int mod, int zigzag, int less){
  int res = 0;
  if(dp[keta][last][mod][zigzag][less] != -1)return dp[keta][last][mod][zigzag][less];
  if(keta == lena){
    if(mod == 0 && less == 1 && !(keta == 1 && zigzag == 1))res = 1;
    else res = 0;
  }
  else if(keta == 0){
    for(int i = 1;i <= 9;i++){
      if(i < a[0] - '0')
	res += solvea(1, i, i % m, 0, 1) + solvea(1, i, i % m, 1, 1);
      if(i == a[0] - '0')
	res += solvea(1, i, i % m, 0, 0) + solvea(1, i, i % m, 1, 0);
      if(i > a[0] - '0')
	res += solvea(1, i, i % m, 0, 2) + solvea(1, i, i % m, 1, 2);
    }
  }
  else{
    if(mod == 0 && !(keta == 1 && zigzag == 1))res++;
    if(zigzag == 0){
      for(int i = 0;i < last;i++){
	if(less == 0){
	  if(i < a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 1, 1);
	  if(i == a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 1, 0);
	  if(i > a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 1, 2);
	}
	else{
	  res += solvea(keta + 1, i, (mod * 10 + i) % m, 1, less);
	}
      }
    }
    if(zigzag == 1){
      for(int i = last + 1;i <= 9;i++){
	if(less == 0){
	  if(i < a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 0, 1);
	  if(i == a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 0, 0);
	  if(i > a[keta] - '0')
	    res += solvea(keta + 1, i, (mod * 10 + i) % m, 0, 2);
	}
	else{
	  res += solvea(keta + 1, i, (mod * 10 + i) % m, 0, less);
	}
      }
    }
  }
  return dp[keta][last][mod][zigzag][less] = res % 10000;
}

int solveb(int keta, int last, int mod, int zigzag, int less){
  int res = 0;
  if(dp[keta][last][mod][zigzag][less] != -1)return dp[keta][last][mod][zigzag][less];
  if(keta == lenb){
    if(mod != 0 || less == 2)res = 0;
    else res = 1;   
  }
  else if(keta == 0){
    for(int i = 1;i <= 9;i++){
      if(i < b[0] - '0')
	res += solveb(1, i, i % m, 0, 1) + solveb(1, i, i % m, 1, 1);
      if(i == b[0] - '0')
	res += solveb(1, i, i % m, 0, 0) + solveb(1, i, i % m, 1, 0);
      if(i > b[0] - '0')
	res += solveb(1, i, i % m, 0, 2) + solveb(1, i, i % m, 1, 2);
    }
  }
  else{
    if(mod == 0 && !(keta == 1 && zigzag == 1))res++;
    if(zigzag == 0){
      for(int i = 0;i < last;i++){
	if(less == 0){
	  if(i < b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 1, 1);
	  if(i == b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 1, 0);
	  if(i > b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 1, 2);
	}
	else{
	  res += solveb(keta + 1, i, (mod * 10 + i) % m, 1, less);
	}
      }
    }
    else{
      for(int i = last + 1;i <= 9;i++){
	if(less == 0){
	  if(i < b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 0, 1);
	  if(i == b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 0, 0);
	  if(i > b[keta] - '0')
	    res += solveb(keta + 1, i, (mod * 10 + i) % m, 0, 2);
	}
	else{
	  res += solveb(keta + 1, i, (mod * 10 + i) % m, 0, less);
	}
      }
    }
  }
  return dp[keta][last][mod][zigzag][less] = res % 10000;
}




int main(){
  scanf("%s\n%s\n%d", a, b, &m);
  lena = strlen(a);
  lenb = strlen(b);
  memset(dp, -1, sizeof(dp));
  ans += solveb(0, 0, 0, 0, 0);
  memset(dp, -1, sizeof(dp));
  ans -= solvea(0, 0, 0, 0, 0);
  printf("%d\n", ans % 10000);
}
