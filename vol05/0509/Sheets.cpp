#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> T;
#define INF (1 << 30)

vector<T> coner;
int ax, ay, bx, by, n, r, p;
int round, area, left_side, right_side, bottom, top;
int imos[3][10500];
int main(){
    while(cin >> n >> r, n | r){
	memset(imos, 0, sizeof(imos));
	round = area = 0;
	p = 0;
	left_side = bottom = 10500;
	right_side = top = 1;
	coner.clear();
	for(int i = 0;i < n;i++){
	    cin >> ax >> ay >> bx >> by;
	    left_side = min(left_side, ++ax);
	    right_side = max(right_side, ++bx);
	    bottom = min(bottom, ++ay);
	    top = max(top, ++by);
	    
	    coner.push_back(T(P(ax, ay), 1));
	    coner.push_back(T(P(ax, by), -1));
	    coner.push_back(T(P(bx, ay), -1));
	    coner.push_back(T(P(bx, by), 1));
	}
	coner.push_back(T(P(INF, INF), 0));
	sort(coner.begin(), coner.end());
	for(int i = left_side;i < right_side + 2;i++){
	    for(int j = bottom;j < top + 2;j++){
		imos[i % 3][j] = imos[i % 3][j - 1];
		while(coner[p].first == P(i, j)){
		    imos[i % 3][j] += coner[p++].second;
		}
	    }
	    for(int j = bottom;j < top + 2;j++){
		imos[i % 3][j] += imos[(i - 1) % 3][j];
		if(imos[i % 3][j])area++;
		if(!!imos[i % 3][j] != !!imos[i % 3][j - 1])round++;
		if(!!imos[i % 3][j] != !!imos[(i - 1) % 3][j])round++; 
	    }

	}
	cout << area << endl;
	if(r == 2)cout << round << endl;
    }
    return 0;
}
