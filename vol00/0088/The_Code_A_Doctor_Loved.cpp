#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

map<char, string> dict;
map<string, char> tcid;
void init(){
    dict[' '] = "101";
    dict['\''] = "000000";
    dict[','] = "000011";
    dict['-'] = "10010001";
    dict['.'] = "010001";
    dict['?'] = "000001";
    dict['A'] = "100101";
    dict['B'] = "10011010";
    dict['C'] = "0101";
    dict['D'] = "0001";
    dict['E'] = "110";
    dict['F'] = "01001";
    dict['G'] = "10011011";
    dict['H'] = "010000";
    dict['I'] = "0111";
    dict['J'] = "10011000";
    dict['K'] = "0110";
    dict['L'] = "00100";
    dict['M'] = "10011001";
    dict['N'] = "10011110";
    dict['O'] = "00101";
    dict['P'] = "111";
    dict['Q'] = "10011111";
    dict['R'] = "1000";
    dict['S'] = "00110";
    dict['T'] = "00111";
    dict['U'] = "10011100";
    dict['V'] = "10011101";
    dict['W'] = "000010";
    dict['X'] = "10010010";
    dict['Y'] = "10010011";
    dict['Z'] = "10010000";
    tcid["00000"] ='A';
    tcid["00001"] ='B';
    tcid["00010"] ='C';
    tcid["00011"] ='D';
    tcid["00100"] ='E';
    tcid["00101"] ='F';
    tcid["00110"] ='G';
    tcid["00111"] ='H';
    tcid["01000"] ='I';
    tcid["01001"] ='J';
    tcid["01010"] ='K';
    tcid["01011"] ='L';
    tcid["01100"] ='M';
    tcid["01101"] ='N';
    tcid["01110"] ='O';
    tcid["01111"] ='P';
    tcid["10000"] ='Q';
    tcid["10001"] ='R';
    tcid["10010"] ='S';
    tcid["10011"] ='T';
    tcid["10100"] ='U';
    tcid["10101"] ='V';
    tcid["10110"] ='W';
    tcid["10111"] ='X';
    tcid["11000"] ='Y';
    tcid["11001"] ='Z';
    tcid["11010"] =' ';
    tcid["11011"] ='.';
    tcid["11100"] =',';
    tcid["11101"] ='-';
    tcid["11110"] ='\'';
    tcid["11111"] ='?';
}

string solve(string a){
    string tmp = "";
    string res = "";
    if(a == "")return a;
    for(int i = 0;i < a.size();i++){
	tmp += dict[a[i]];
    }
    while(tmp.size()%5)tmp+="0";
    for(int i = 0;i < tmp.size();i += 5){
	string x = "";
	for(int j = 0;j < 5;j++){
	    x += tmp[i + j];
	}
	res += tcid[x];
    }
    return res;
}
bool fin = false;
string get_line(){
    string res = "";
    while(true){
	char t = getchar();
	if(t == '\n' || t == EOF){
	    if(t == EOF)fin = true;
	    break;
	}
	res += t;
    }
    return res;
}

int main(){
    init();
    while(!fin){
	string res = solve(get_line());
	if(!fin && res != "")cout << res << endl;
    }
    return 0;
}
