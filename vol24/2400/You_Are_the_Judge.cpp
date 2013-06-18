#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int t, p, r, tID, pID, times;
int point[100], wrong[100][100], penalty[100], ans[100];
string message;

bool AC_comp(const int &a, const int &b){
    if(point[a] == point[b]){
	if(penalty[a] == penalty[b])
	    return a < b;
	return penalty[a] < penalty[b];
    }
    return point[a] > point[b];
}

int main(){
    while(true){
	cin >> t >> p >> r;
	if(t == 0 && p == 0 && r == 0)return 0;
	memset(point, 0, sizeof(point));
	memset(penalty, 0, sizeof(penalty));
	memset(wrong, 0, sizeof(wrong));
	for(int i = 0;i < r;i++){
	    cin >> tID >> pID >> times >> message;
	    if(message == "CORRECT"){
		point[tID]++;
		penalty[tID] += times + wrong[tID][pID] * 1200;
	    }
	    else{
		wrong[tID][pID]++;
	    }
	}
	for(int i = 0;i < t;i++){
	    ans[i] = i + 1;
	}
	sort(ans, ans + t, AC_comp);
	for(int i = 0;i < t;i++){
	    int team = ans[i];
	    cout << team << ' ' << point[team] << ' ' << penalty[team] << endl;
	}
    }
}
