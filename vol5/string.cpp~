#include<cstdio>
#include<cstring>
int n;
char s[120],ss[120];
int main(){
  while(true){
    scanf("%d",&n);
    if(n==0)return 0;
    scanf("%s",s);
    for(int j=0;j<n;j++){
      int counter=1,pos=0;
      char now=s[0];
      for(int i=1;i<strlen(s);i++){
	if(now!=s[i]){
	  int p;
	  sprintf(ss+pos,"%d%c%n",counter,now,&p);
	  pos+=p;
	  counter=1;
	  now=s[i];
	}
	else counter++;
      }
      sprintf(ss+pos,"%d%c\0",counter,now);
      strcpy(s,ss);
    }
    printf("%s\n",s);
  }
}
