#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef pair<int, int> P;
int main(){
    int n, p, d1, d2;
    while(cin >> n, n){
	vector<P> patient;
	for(int i = 0;i < n;i++){
	    cin >> p >> d1 >> d2;
	    patient.push_back(P(d1 + d2, p));
	}
	sort(patient.begin(), patient.end());
	cout << patient[n - 1].second << " " << patient[n - 1].first << endl;
    }
    return 0;
}
