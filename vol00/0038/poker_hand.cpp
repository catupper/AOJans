#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    vector<int> a(5);
    while(~scanf("%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4])){
	sort(a.begin(), a.end());
	if(count(a.begin(), a.end(), a[3]) == 4){
	    cout << "four card" << endl;
	}
	else if(count(a.begin(), a.end(), a[0]) + count(a.begin(), a.end(), a[4]) == 5){
	    cout << "full house" << endl;
	}
	else if(count(a.begin(), a.end(), a[2]) == 3){
	    cout << "three card" << endl;
	}
	else if(count(a.begin(), a.end(), a[1]) + count(a.begin(), a.end(), a[3]) == 4){
	    cout << "two pair" << endl;
	}
	else{
	    
	    for(int i = 0;i < 5;i++){
		if(count(a.begin(), a.end(), a[i]) == 2){
		    cout << "one pair" << endl;
		    goto done;
		}
	    }
	    if(a[0] == 1 && a[1] == 10 && a[2] == 11 && a[3] == 12 && a[4] == 13){
		cout << "straight" << endl;
		goto done;
	    }
	    for(int i = 0;i < 5;i++){
		if(a[i] != a[0] + i)break;
		if(i == 4){
		    cout << "straight" << endl;
		    goto done;
		}
	    }
	    cout << "null" << endl;
	}
    done :;
    }
}
