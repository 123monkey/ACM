#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
typedef __int64 INT;
INT bestNum;   //Լ��������
INT bestSum;   //Լ����������Լ������
const int M=1000; //�������ĸ��� 
INT n=500000;//��n���ڵ����еķ�����
INT rprim[M][2];
//2*3*5*7*11*13*17>n������ֻ�迼�ǵ�17����
INT prim[14]={2,3,5,7,11,13,17,19,23,29};  

//��ǰ�ߵ�num������������õ�k��������num��Լ������Ϊsum��
//��k�������ĸ�������Ϊlimit
void getNum(INT num,INT k,INT sum,INT limit)  {
 	if(num>n)return;
	if(sum>bestSum){
		bestSum = sum;
		bestNum = num;
	}else if(sum == bestSum && num < bestNum){  //Լ������һ��ʱ��ȡС��
		bestNum = num;
	}
	if(k>=7) return; //ֻ�迼�ǵ�����17,��prim[6]
  
	for(INT i=1,p=1;i<=limit;i++){   //����kȡi��
		p*=prim[k];
		getNum(num*p,k+1,sum*(i+1),i);
	}
}

INT log2(INT n){   //����ڵ���log2��n������С����
	INT i = 0;
	INT p = 1;
	while(p<n){
		p*=2;
		i++;
	}
	return i;
}

int getrprim(){
	int i = 0;
	while(n>0){
		bestNum = 1;
		bestSum = 1;
		getNum(1,0,1,log2(n));
		n = bestNum - 1;
		rprim[i][0]=bestNum;
		rprim[i][1]=bestSum;
		i++;
	}
	return i;	
}


int main()
{

 n = 500000;
 printf("%d\n",getrprim());   //�������ĸ���
 getchar();
 return 0;
}
