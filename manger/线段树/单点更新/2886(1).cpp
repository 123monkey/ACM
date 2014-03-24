#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

struct aNode{
	int l,r;
	int n;
};

aNode node[2000000];
char name[500001][12];
int num[500001];



void makeTree(int k,int l,int r)
{
	node[k].l = l;
	node[k].r = r;
	node[k].n = r-l+1;
	if(l==r)
		return;
	int mid = (l+r)/2;
	makeTree(2*k,l,mid);
	makeTree(2*k+1,mid+1,r);
}


int query(int k,int n)   //��ѯ��ǰ��n�����ĺ���
{
	if(node[k].l == node[k].r)
		return node[k].l;
	if(n<=node[2*k].n)
		return query(2*k,n);
	else
		return query(2*k+1,n-node[2*k].n);
}

void deleteNum(int k,int n)   //ɾȥ��Ϊn����
{
	node[k].n--;
	if(node[k].l == node[k].r)
		return;
	int mid = (node[k].l + node[k].r)/2;
	if(n<=mid)
		deleteNum(2*k,n);
	else
		deleteNum(2*k+1,n);
}


int main()
{
	int n,k;
	int i;
	int no;
	int t;
	int x;
	int p;
    //�������ķ�����
	int max[35][2] = {498960,200,332640,192,277200,180,221760,168,166320,160,110880,144,83160,128,55440,120,50400,108,45360,100,27720,96,25200,90,20160,84,15120,80,10080,72,7560,64,5040,60,2520,48,1680,40,1260,36,840,32,720,30,360,24,240,20,180,18,120,16,60,12,48,10,36,9,24,8,12,6,6,4,4,3,2,2,1,1};
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		p = 0;
		while(n<max[p][0])p++;
		x = max[p][0];   //xΪС�ڵ���n���������
		makeTree(1,0,n-1);
		for(i=0;i<n;i++)
		{
			scanf("%s",name[i]);
			scanf("%d",&num[i]);
		}
		i=1;
		t = n;
		no=k;    //��Ϊk����ʣ�������ŵ�no��
		k--;
		while(i<x){    //�㵽��x���˺󼴿�

 			n--;
			if(n>0){
			
				deleteNum(1,k);   //ɾ����Ϊk����
				//�����noֵ����ʣ�����е��źţ�
                no+=num[k];
				if(num[k]>0)
					no--;
				no = (no%n+n)%n;
				if(no==0)
					no+=n;
				k=query(1,no);	//��ԭ�������
				i++;
			}
		}
		printf("%s %d\n",name[k],max[p][1]);

	}
	return 0;
}
