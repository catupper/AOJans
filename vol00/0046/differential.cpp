#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    double x;
    cin >> x;
    double minimum = x, maximum = x;
    while(cin >> x){
	minimum = min(minimum, x);
	maximum = max(maximum, x);
    }
    cout << maximum - minimum << endl;
    return 0;
}
