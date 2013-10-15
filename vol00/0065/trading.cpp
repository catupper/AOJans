#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
bool end;
map<int, int> one, two;
int getline(){
    char res[1050];
    int p = 0;
    while(true){
	char c = getchar();
	if(c == EOF)end = true;
	if(c == '\n' || c == EOF){
	    if(p == 0)return -1;
	    sscanf(res, "%d,%*d", &p);
	    return p;
	}
	res[p++] = c;	
    }
}
int main(){
    while(!end){
	int p = getline();
	if(p == -1)swap(one, two);
	else{
	    two[p]++;
	}
    }    
    map<int, int>::iterator it = one.begin();
    while(it != one.end()){
	if(two[it->first]){
	    cout << it->first << " "<< (it->second) + two[it->first]<<endl;
	}
	it++;
    }
    return 0;
}
