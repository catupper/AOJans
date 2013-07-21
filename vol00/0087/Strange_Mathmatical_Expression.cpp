#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    stack<double> st;
    double a, b;
    char s[105];
    char w;
    while(~scanf("%s%c", s, &w)){
	switch(s[0]){
	case '+':
	    a = st.top();st.pop();
	    b = st.top();st.pop();
	    st.push(b+a);
	    break;
	case '-':
	    if(s[1] != '\0')goto a;
	    a = st.top();st.pop();
	    b = st.top();st.pop();
	    st.push(b-a);
	    break;
	case '*':
	    a = st.top();st.pop();
	    b = st.top();st.pop();
	    st.push(b*a);
	    break;
	case '/':
	    a = st.top();st.pop();
	    b = st.top();st.pop();
	    st.push(b/a);
	    break;
	default:
	a:
	    sscanf(s, "%lf", &a);
	    st.push(a);
	}
	if(w == '\n'){
	    printf("%.5lf\n",st.top());
	    while(!st.empty())
		st.pop();
	}
    }
    return 0;
}
