#include<cstdio>
#include<vector>
using namespace std;

int main(){
  while(1){
    int n;
    scanf("%d",&n);
    if(n == 0)return 0;
    int color = -1, go;
    vector<int> stones;
    for(int i = 1;i <= n;i++){
      scanf("%d", &go);
      
      if(i % 2 == 1){
	if(color != go){
	  stones.push_back(1);
	}
	else{
	  stones[stones.size() - 1]++;
	}
      }
      else{
	if(color != go){
	  if(stones.size() == 1){
	    stones[stones.size() - 1]++;
	  }
	  else{
	    int tmp = stones.back();
	    stones.pop_back();
	    stones[stones.size() - 1] += tmp + 1;
	  }
	}
	else{
	  stones[stones.size() - 1]++;
	}
      }
      color = go;
    }
    int res = 0;
    for(int i = stones.size() - 1;i >= 0;i--){
      if(color == 0)res += stones[i];
      color ^= 1;
    }
    printf("%d\n", res);
  }
}
