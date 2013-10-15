#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct P{
    P(){}
    P(double a, double b){
	x = a;y = b;
    }
    double x, y;
    double det(P p){
	return x * p.y - y * p.x;
    }
    P operator-(P p){
	return P(x - p.x, y - p.y);
    }
};

bool comp_p(const P &x, const P &y){
    if(x.x == y.x)return x.y < y.y;
    return x.x < y.x;
}

P ans[1050];

int main(){
    int n;
    double a, b;
    while(cin >> n, n){
	vector<P> ps;
	for(int i = 0;i < n;i++){
	    scanf("%lf,%lf", &a, &b);
	    ps.push_back(P(a, b));
	}
	sort(ps.begin(), ps.end(), comp_p);
	int res = 0;
	for(int i = 0;i < ps.size();i++){
	    while(res > 1 && (ans[res - 1] - ans[res - 2]).det(ps[i] - ans[res - 1]) <= 0)res--;
	    ans[res++] = ps[i];
	}
	for(int i = ps.size() - 2, t = res;i >= 0;i--){
	    while(res > t && (ans[res - 1] - ans[res - 2]).det(ps[i] - ans[res - 1]) <= 0)res--;
	    ans[res++] = ps[i];
	}
	res--;
	cout << n - res << endl;
    }
}
