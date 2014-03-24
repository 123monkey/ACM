#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;

//����
//root(a+b)=root(root(a) + root(b)) 
//root(a*b)=root(root(a) * root(b)) 
//root(a)=root(root(a/10) + a%10) 

//һ��n������
//ģ�� 
int root(int n){
	while(n>9)n=n%10+n/10;
	return n;
} 
//�ҹ��� 
int _root(int n){
	return n?(n+8)%9+1:0;
} 
//�߾���
int __root(char *p){
	int n=0;
	for(int i=0;p[i];i++)n+=p[i]-'0';
	return n?(n+8)%9+1:0;
} 
//����n^n������
//�ҹ���
int treeroot(int n){
	int tree[19]={9,1,4,9,4,2,9,7,1,9,1,5,9,4,7,9,7,8};
	return tree[n%18];
} 
//ģ���a^b������

//���� a^b������
//ѭ������
int _treeroot(int a,int b){
	a=root(a);
	int ans=1;
	while(b--)ans=root(ans*a);
	return ans;
} 
//�����Ʒ�
int mytreeroot(int a,int b){
	a=root(a);
	int t=a,ans=1;
	while(b){
		if(b&1)ans=root(ans*t);
		b>>=1;
		t=root(t*t);
	}
	return ans;
} 

int main()
{
	int a,b;
	while(cin>>a){
		cout<<"root1-->"<<root(a)<<endl;
		cout<<"root2-->"<<_root(a)<<endl;
		cout<<"treeroot1-->"<<treeroot(a)<<endl;
		cout<<"treeroot2-->"<<_treeroot(a,a)<<endl;
		
	}
	return 0;
}
