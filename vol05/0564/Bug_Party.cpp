#include<cstdio>
#include<algorithm>
using namespace std;

struct BIT{
  long long int a;
  int num;
};

struct BUG{
  int a, b, pos;
};

bool acomp(const BUG& x, const BUG& y){
  return x.a < y.a;
}

bool bcomp(const BUG& x, const BUG& y){
  return x.b > y.b;

}

BIT bit[1 << 20];
BUG bug[1 << 20];

int n, nbin = 1, ans = 0, up, down;

void addbit(int x){
  int pos = bug[x].pos;
  while(pos <= nbin){
    bit[pos].a += bug[x].a;
    bit[pos].num++;
    pos += pos & -pos;
  }
}

int able(int pos, int limit){
  long long int asum = 0;
  long long int num = 0;
  while(pos != 0){
    asum += bit[pos].a;
    num += bit[pos].num;
    pos -= pos & -pos;
  }
  if(limit * num >= asum)return num;
  else return -1;
}

int main(){
  scanf("%d" , &n);
  while(n > nbin)nbin <<= 2;
  for(int i = 0;i < n;i++){
    scanf("%d%d", &bug[i].a, &bug[i].b);
    bug[i].pos = 0;
    bit[i].a = 0;
    bit[i].num = 0;
  }
  sort(bug, bug + n, acomp);
  for(int i = 1;i <= n;i++){
    bug[i - 1].pos = i;
  }
  sort(bug, bug + n, bcomp);
  
  for(int i = 0;i < n;i++){
    addbit(i);
    up = nbin;
    down = 1;
    while(up - down > 1){
      int mid = (up + down) / 2;
      int tmp = able(mid, bug[i].b);
      if(tmp == -1)
	up = mid;
      else
	down = mid;
    }
    ans = max(ans, able(down, bug[i].b));
  }
  printf("%d\n", ans);
}
