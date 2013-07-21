#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

map<long long, long long> score;
set<long long, greater<long long> > scores;
int main(){
    long long a, b, x;
    while(true){
	scanf("%lld,%lld", &a, &b);
	if(a == 0 && b == 0)break;
	score[a] = b;
	scores.insert(b);
    }
    while(cin){
	cin >> x;
	cout << distance(scores.begin(), scores.lower_bound(score[x])) + 1 << endl;
    }
    return 0;
}
