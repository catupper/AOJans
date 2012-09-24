#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
int  sheets[3][10007], tmp[10007];



int main(){
  while(1){
    int n, r;
    int x1, y1, x2, y2, mx = 0, my = 0, menseki = 0, gaishuu = 0;
    vector<pair<int, int> > points;
    map<pair<int ,int> , int> nums;
    scanf("%d%d", &n, &r);
    memset(sheets, 0, sizeof(sheets));
    if(n == 0 && r == 0)return 0;
    for(int i = 0;i < n;i++){
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1++,y1++,x2++,y2++;
      points.push_back(make_pair(x1, y1));
      points.push_back(make_pair(x1, y2));
      points.push_back(make_pair(x2, y1));
      points.push_back(make_pair(x2, y2));
      if(nums.count(make_pair(x1, y1)) == 0)nums[make_pair(x1, y1)] = 0;
      if(nums.count(make_pair(x2, y1)) == 0)nums[make_pair(x2, y1)] = 0;
      if(nums.count(make_pair(x1, y2)) == 0)nums[make_pair(x1, y2)] = 0;
      if(nums.count(make_pair(x2, y2)) == 0)nums[make_pair(x2, y2)] = 0;
      nums[make_pair(x1, y1)]++;
      nums[make_pair(x2, y2)]++;
      nums[make_pair(x1, y2)]--;
      nums[make_pair(x2, y1)]--;
      mx = max(mx, x1);
      mx = max(mx, x2);
      my = max(my, y1);
      my = max(my, y2);
    }
    sort(points.begin(), points.end(), greater< pair<int, int> >());
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1;i <= mx ; i++){
      for(int j = 1;j <= my + 1; j++){
	if(points.back().first == i && points.back().second == j){
	  tmp[j] += nums[points.back()];
	  pair<int, int> tmpr = points.back();
	  while(points.back() == tmpr)points.pop_back();
	}
	sheets[i % 3][j] = sheets[i % 3][j - 1] + tmp[j];
	if(sheets[i % 3][j] > 0)menseki++;
	if(r == 2){
	  if(sheets[i % 3][j] > 0 ){
	    if(sheets[(i - 1) % 3][j] == 0)gaishuu++;
	    if(sheets[i % 3][j - 1] == 0)gaishuu++;
	  }
	  if(sheets[i % 3][j] == 0 ){
	    if(sheets[(i - 1) % 3][j] > 0)gaishuu++;
	    if(sheets[i % 3][j - 1] > 0)gaishuu++;
	  }
	}
      }
    }
    printf("%d\n", menseki);
    if(r == 2){
      printf("%d\n", gaishuu);
    }
  }
}
