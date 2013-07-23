#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define INF (1 << 29)
int main(){
  char chair[105];
  int n, m;
  char c;
  while(cin >> n >> m, n){
    fill(chair, chair + n, '#');
    chair[n] = 0;
    for(int i = 0;i < m;i++){
      cin >> c;
      switch(c){
      case 'A':
      left :
	for(int j = 0;j < n;j++){
	  if(chair[j] == '#'){
	    chair[j] = c;
	    break;
	  }
	}
	break;
      case 'B':
	for(int j = n - 1;j >= 0;j--){
	  if((j == 0 || chair[j - 1] != 'A') && chair[j + 1] != 'A' && chair[j] == '#'){
	    chair[j] = c;
	    break;
	  }
	  if(j == 0)goto left;
	}
	break;
      case 'C':
	for(int j = 0;j < n;j++){
	  if(chair[j] != '#'){
	    if(chair[j + 1] == '#'){
	      chair[j + 1] = c;
	      break;
	    }
	    if(j != 0 && chair[j - 1] == '#'){
	      chair[j - 1] = c;
	      break;
	    }
	  }
	  if(j == n - 1){
	    chair[n / 2] = c;
	  }
	}
	break;
      case 'D':
	int p = 0, s = -1;
	for(int j = 0;j < n;j++){
	  if(chair[j] != '#')continue;
	  int t = INF;
	  for(int k = j;k < n;k++){
	    if(chair[k] != '#'){
	      t = k - j;
	      break;
	    }
	  }
	  for(int k = j;k >= 0;k--){
	    if(chair[k] != '#'){
	      t = min(t, j - k);
	      break;
	    }
	  }
	  if(t > s){
	    p = j;
	    s = t;
	  }
	}
	if(p == INF){
	  chair[n - 1] = c;
	}
	else{
	  chair[p] = c;
	}
	break;
      }
    }
    printf("%s\n", chair);
  }
  return 0;
}
