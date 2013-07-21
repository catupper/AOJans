#include<iostream>
#include<algorithm>

using namespace std;
int a[3], total, les, righ, more;
int main(){
    while(cin){
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if(a[2] >= a[0] + a[1] || a[2] <= a[1] - a[0]){
	    cout << total << " " << righ << " " << more << " " << les << endl;
	    return 0;
	}
	int p = a[2] * a[2];
	int q = a[1] * a[1] + a[0] * a[0];
	if(p > q)les++;
	if(p == q)righ++;
	if(p < q)more++;
	total++;
    }
}
