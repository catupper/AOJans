#include<cstdio>
#include<set>
#include<map>
using namespace std;

int main(){
  while(1){
    int m, n ;
    int seiza[200][2], stars[1000][2];
    set< pair<int, int> > starset;
    scanf("%d", &m);
    if(m == 0){
      return 0;
    }
    for(int i = 0;i < m;i++){
      int xi, yi;
      scanf("%d%d", &xi, &yi);
      seiza[i][0] = xi;
      seiza[i][1] = yi;
    }
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
      int xi, yi;
      scanf("%d%d", &xi, &yi);
      stars[i][0] = xi;
      stars[i][1] = yi;
      starset.insert(make_pair(xi, yi));
    }
    for(int i = 0;i < n;i++){
      int xdis = stars[i][0] - seiza[0][0];
      int ydis = stars[i][1] - seiza[0][1];
      int j;
      for(j = 1;j < m;j++){
	if(starset.find(make_pair(seiza[j][0] + xdis, seiza[j][1] + ydis)) == starset.end()){
	  break;
	}
      }
      if(j == m){
	printf("%d %d\n", xdis, ydis);
	break;
      }
    }
  }
}
