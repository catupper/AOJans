#include<iostream>
#include<algorithm>

using namespace std;

int dim[105], a, b;
int main(){

    while(true){
	fill(dim, dim + 105, 0);
	while(true){
	    if(cin >> a >> b);
	    else return 0;

	    if(a == 0 && b == 0)break;
	    dim[a]++;dim[b]++;	    
	}
	int ok = true;
	if(dim[1] % 2 == 0)ok = false;
	if(dim[2] % 2 == 0)ok = false;
	for(int i = 3;i < 105;i++){
	    if(dim[i] % 2 == 1)ok = false;
	}
	if(ok)cout << "OK"<<endl;
	else cout <<"NG"<<endl;
    }
    return 0;
}
