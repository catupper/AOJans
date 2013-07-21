#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

set<int, greater<int> > rank;
map<int, int> points;
int main(){
    int a, b;
    while(scanf("%d,%d", &a, &b), a){
	rank.insert(b);
	points[a] = b;
    }
    while(~scanf("%d", &a)){
	cout << distance(rank.begin(), rank.lower_bound(points[a])) + 1 << endl;
    }
    return 0;
}
