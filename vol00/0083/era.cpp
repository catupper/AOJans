#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> T;




int main(){
    T m = T(1868, P(9, 8));
    T t = T(1912, P(7, 30));
    T s = T(1926, P(12, 25));
    T h = T(1989, P(1, 8));
    int a, b, c;
    while(cin >> a >> b >> c){
	T tmp = T(a, P(b, c));
	string res = "heisei";
	int rem = tmp.first - h.first + 1;
	if(tmp < m){
	    res = "pre-meiji";
	    cout << res << endl;
	    continue;
	}
	else if(tmp < t){
	    res = "meiji";
	    rem = tmp.first - m.first + 1;
	}
	else if(tmp < s){
	    res = "taisho";
	    rem = tmp.first - t.first + 1;
	}
	else if(tmp < h){
	    res = "showa";
	    rem = tmp.first - s.first + 1;
	}
	cout << res << " " << rem << " " <<b <<" "<<c<<endl;
    }
    return 0;
}
