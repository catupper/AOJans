#include<iostream>
#include<algorithm>
using namespace std;

int pat;
string eq;

bool value(char x){
    if(x == 'T')return true;
    if(x == 'F')return false;
    return pat & (1 << (x - 'a'));
}

bool eval(int left, int right){
    if(left + 1 == right)return value(eq[left]);
    if(eq[left] == '-')return !eval(left + 1, right);
    int s = 0;
    for(int i = left + 1;i < right - 1;i++){
	if(eq[i] == '(')s++;
	if(eq[i] == ')')s--;
	if(s != 0)continue;
	if(eq[i] == '*'){
	    return eval(left + 1, i) & eval(i + 1, right - 1);
	}
	if(eq[i] == '+'){
	    return eval(left + 1, i) | eval(i + 1, right - 1);
	}
	if(eq[i] == '-' && eq[i + 1] == '>'){
	    return (!eval(left + 1, i)) | eval(i + 2, right - 1);
	}
    }
}


int main(){
    while(true){
	cin >> eq;
	if(eq == "#")return 0;
	int center = 0;
	bool equal = true;
	while(eq[center] != '=')center++;
	for(int i = 0;i < (1 << 11);i++){
	    pat = i;
	    if(eval(0, center) != eval(center + 1, eq.size())){
		equal = false;
		break;
	    }
	}
	if(equal)
	    cout << "YES" << endl;
	else
	    cout << "NO" << endl;
    }
}
