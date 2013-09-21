#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=350;

class Gauss{
	int var,equ;//��equ�����̣�var����Ԫ��
	int matrix[N][N],free_x[N],ans[N];// matrixΪ�������ansΪ�⼯,free_x�ж��Ƿ��ǲ�ȷ���ı�Ԫ.
	public:
	void init(int n,int m){this->equ=m;this->var=n;memset(matrix,0,sizeof(matrix));}
	int getanswer();
	//��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).
	//(-2��ʾ�и������⣬���������⣬-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
};

int Gauss::getanswer(){
	int tmp;
	int max_r,ta,tb,k,col=0;
	//// ת��Ϊ������.
	for(k=0;k<equ && col<var ;k++,col++){
		max_r=k;//�ҵ���col��Ԫ�ؾ���ֵ�����������k�н���.(Ϊ���ڳ���ʱ��С���)
		for(int i=k+1;i<equ;i++){
			if(abs(matrix[i][col]) > abs(matrix[max_r][col]))max_r=i;
		}
		
		if(max_r != k){// ���k�н���
			for(int j=k;j<var+1;j++)swap(matrix[k][j],matrix[max_r][j]);
		}
		//// ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ�� 	
		if(matrix[k][col] == 0){k--;continue;}
		
		ta=matrix[k][col];
		//֮���е�Ҫ��Ϊ0 
		for(int i=k+1; i<equ ;i++){
			if(matrix[i][col] != 0){
				tb=matrix[i][col];
				for(int j=col;j<=var;j++){
					matrix[i][j]=matrix[i][j]*ta-matrix[k][j]*tb;
				}
			}
		}
		
	}
	//// 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0). 
	for(int i=k;i<equ;i++){
		if(matrix[i][var]!=0)return -1;//�޽� 
	}

	// ���������: ��var * (var + 1)���������г���(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.    
	// �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.
	if(k!=col || col<var){
		
		int free_x_num=0,free_index;
		for(int i=k-1;i>=0;i--,free_x_num=0){
// ��i��һ��������(0, 0, ..., 0)���������Ϊ�����������ڵ�k�е���equ��.            
// ͬ������i��һ��������(0, 0, ..., a), a != 0��������������޽��.
// free_x_num�����жϸ����еĲ�ȷ���ı�Ԫ�ĸ������������1�������޷���⣬������ȻΪ��ȷ���ı�Ԫ.
			for(int j=0;j<var;j++){
				if(matrix[i][j] && free_x[j])free_x_num++,free_index=j;
			}
			
			if(free_x_num>1)continue;// �޷�����ȷ���ı�Ԫ.
// ˵����ֻ��һ����ȷ���ı�Ԫfree_index����ô���������ñ�Ԫ���Ҹñ�Ԫ��ȷ����.
			tmp=matrix[i][var];
			
			for(int j=0;j<var;j++){
				if(matrix[i][j] && j!=free_index)tmp-=matrix[i][j]*ans[j];
			}
			
			ans[free_index]=tmp/matrix[i][free_index];// ����ñ�Ԫ
			
			free_x[free_index]=0;// �ñ�Ԫ��ȷ����.
			
		}
		return var - k;// ���ɱ�Ԫ��var - k��.
	}
// 3. Ψһ������: ��var * (var + 1)�����������γ��ϸ����������.    
// �����Xn-1, Xn-2 ... X0.
	for(int i=var-1;i>=0;i--){
		tmp=matrix[i][var];
		for(int j=i+1;j<var;j++){
			tmp-=matrix[i][j]*ans[j];
		}
		if(tmp % matrix[i][i])return -1;// ˵���и������⣬����������.
		ans[i]=tmp/matrix[i][i];
	}
	return 0;	
}



int main()
{


    return 0;
}
