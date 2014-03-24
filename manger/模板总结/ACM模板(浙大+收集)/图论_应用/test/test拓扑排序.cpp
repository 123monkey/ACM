#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������,����ͼ���ڽ�����ʽ,���Ӷ�O(n^2)
//����޷��������,����0,���򷵻�1,ret�����������
//����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩ0
#define MAXN 100

int mat[MAXN][MAXN];

int toposort(int n,int mat[][MAXN],int* ret){
    int d[MAXN],i,j,k;
    for (i=0;i<n;i++)
        for (d[i]=j=0;j<n;d[i]+=mat[j++][i]);
		for (k=0;k<n;ret[k++]=i){
			for (i=0;d[i]&&i<n;i++);
			if (i==n)
				return 0;
			for (d[i]=-1,j=0;j<n;j++)
				d[j]-=mat[i][j];
		}
		return 1;
}


int main()
{
	int n = 9;
	int a[][9] = {
		{0,0,1,0,0,0,0,1,0},
		{0,0,1,1,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0},
		{0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0},
	};
	int ret[10];
	int i,  j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			mat[i][j] = a[i][j];
		}
	}
	toposort(n, mat, ret);
	for (i = 0; i < n; ++i) {
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	
	return  0;
}