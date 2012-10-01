#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int points[100005][2], xs[100005], ys[100005], n, w, h;
  long long int sums = 0;
  scanf("%d%d%d", &w, &h, &n);
  for(int i = 0;i < n;i++){
    scanf("%d%d", xs + i, ys + i);
    points[i][0] = xs[i];
    points[i][1] = ys[i];
  }
  sort(xs, xs + n);
  sort(ys, ys + n);
  long long int ans = -1;
  int ansx, ansy;
  int up = min( (n / 2) + 2, n - 1);
  int down = max(0, (n / 2) - 2);


  for(int i = down;i <= up;i++){
    for(int j = down;j <= up;j++){
      long long int  res = 0, far = 0, d;
      for(int k = 0;k < n;k++){
	d = abs(points[k][0] - xs[i]) + abs(points[k][1] - ys[j]);
	far = max(far, d);
	res += d * 2;
      }
      if(ans == -1 || ans > res - far){
	ans = res - far;
	ansx = xs[i];
	ansy = ys[j];
      }
    }
  }
  printf("%lld\n", ans);
  printf("%d %d\n", ansx, ansy);
  return 0;
}
