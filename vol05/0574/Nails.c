#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
int n, m;
int nails[2][5009];
int ans;
map<pair<int, int> , int> tops;
vector<pair<int, int> > toppoints;

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0;i < m;i++){
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);
    a--;b--;
    toppoints.push_back(make_pair(a, b));
    if(tops.find(make_pair(a, b)) == tops.end())tops[make_pair(a, b)] = 0;
    tops[make_pair(a, b)] = max(x + 1, tops[make_pair(a, b)]);
  }
  sort(toppoints.begin(), toppoints.end(), greater<pair<int, int> >());
  memset(nails, 0, sizeof(nails));
  for(int i = 0;i <= n;i++){
    memset(nails[(i + 1) % 2], 0, sizeof(int) * 5009);
    for(int j = 0;j <= n;j++){
      if(!toppoints.empty() && toppoints.back() == make_pair(i, j)){
	nails[i % 2][j] = max(tops[make_pair(i, j)], nails[i % 2][j]);
	while(!toppoints.empty() && toppoints.back() == make_pair(i, j)){
	  toppoints.pop_back();
	}
      }
      if(nails[i % 2][j] != 0)ans++;
      nails[(i + 1) % 2][j] = max(nails[(i + 1) % 2][j], nails[i % 2][j] - 1);
      nails[(i + 1) % 2][j + 1] = max(nails[(i + 1) % 2][j + 1], nails[i % 2][j] - 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
