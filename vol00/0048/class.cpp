#include<iostream>
#include<algorithm>

using namespace std;

double w[] = {48, 51,54, 57, 60, 64, 69, 75, 81, 91};
string c[] = {
    "light fly",
    "fly",
    "bantam",
    "feather",
    "light",
    "light welter",
    "welter",
    "light middle",
    "middle",
    "light heavy",
    "heavy"
};
int main(){
    double n;
    while(cin >> n){
	for(int i = 0;i < 10;i++){
	    if(n <= w[i]){
		cout << c[i] << endl;
		break;
	    }
	    if(i == 9)
		cout << "heavy" << endl;
	}
    }
    return 0;
}
