#include<stdio.h>
#include<string.h>
#include<set>
#include<map>
using namespace std;
int main(){
  while(1){
    int n, max = 0;
    int points[3000][2];
    set<pair<int, int> > fields;

    scanf("%d", &n);
    if(n == 0){
      return 0;
    }
    for(int i = 0;i < n;i++){
      int xi, yi;
      scanf("%d%d", &xi, &yi);
      points[i][0] = xi;
      points[i][1] = yi;
      fields.insert(make_pair(xi, yi));
    }
    
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++){
	if(i == j)continue;
	int xdis = points[i][0] - points[j][0];
	int ydis = points[i][1] - points[j][1];
	if(points[j][0] + ydis < 0 || points[j][0] + ydis > 5000)continue;
	if(points[j][1] - xdis < 0 || points[j][1] - xdis > 5000)continue;
	if(points[i][0] + ydis < 0 || points[i][0] + ydis > 5000)continue;
	if(points[i][1] - xdis < 0 || points[i][1] - xdis > 5000)continue;
	if(fields.find(make_pair(points[j][0] + ydis, points[j][1] - xdis)) == fields.end())continue;
	if(fields.find(make_pair(points[i][0] + ydis, points[i][1] - xdis)) == fields.end())continue;
	if(max < xdis * xdis + ydis * ydis){
	  max = xdis * xdis + ydis * ydis;
	}
      }
    }
    printf("%d\n", max);
  }
}
