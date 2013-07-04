#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

// KMP ƥ���㷨O(M+N)
//ԭ��Ϊstr; ģʽΪpat;
//����next���� 
const int P=100; 
int fail[P];
void initfail(char *pat){
	memset(fail,-1,sizeof(fail));
	for(int i=1,k;pat[i];++i){
		for(k=fail[i-1];k>=0 && pat[i]!=pat[k+1];k=fail[k]);
		if(pat[k+1] == pat[i])fail[i]=k+1; 
	} 	 
} 

//����ƥ��ĵ�һ��λ�� 
//����ƥ��ĸ���  ans
int kmp(char* str, char* pat){
	initfail(pat); 
	int i=0, j=0,ans=0;
	
	while( str[i] && pat[j] ){ 
		if( pat[j] == str[i] ){
			 ++i;
			if(!pat[++j])ans++;	
		}
		else if(j == 0)++i;
		else j = fail[j-1]+1;
	}
	// return ans; 
	if( pat[j] ) return -1;
	else return i-j;
}


int main()
{
	char s1[100],s2[100];
	while(cin>>s1>>s2){
		printf("%d",kmp(s1,s2)); 
	} 
	return 0;
}
