#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

__int64 bestNum;   //Լ��������
__int64 bestSum;   //Լ����������Լ������
const int M=1000;
__int64 n=500000;//��n���ڵ����еķ�����
__int64 rprim[M][2];
//2*3*5*7*11*13*17>n������ֻ�迼�ǵ�17����
__int64 sushu[14]={2,3,5,7,11,13,17,19,23,29};  

//��ǰ�ߵ�num������������õ�k��������num��Լ������Ϊsum��
//��k�������ĸ�������Ϊlimit
void getNum(__int64 num,__int64 k,__int64 sum,__int64 limit)  {
 	if(num>n)return;
	if(sum>bestSum){
		bestSum = sum;
		bestNum = num;
	}else if(sum == bestSum && num < bestNum){  //Լ������һ��ʱ��ȡС��
		bestNum = num;
	}
	if(k>=7) return; //ֻ�迼�ǵ�����17,��sushu[6]
  
	for(__int64 i=1,p=1;i<=limit;i++){   //����kȡi��
		p*=sushu[k];
		getNum(num*p,k+1,sum*(i+1),i);
	}
}

__int64 log2(__int64 n){   //����ڵ���log2��n������С����
	__int64 i = 0;
	__int64 p = 1;
	while(p<n){
		p*=2;
		i++;
	}
	return i;
}

int main()
{

 n = 500000;
 int i = 0;
	while(n>0){
		bestNum = 1;
		bestSum = 1;
		getNum(1,0,1,log2(n));
		printf("bestNum=%I64d  bestSum=%I64d\n",bestNum,bestSum);
		n = bestNum - 1;
		rprim[i][0]=bestNum;
		rprim[i][1]=bestSum;
		i++;
	}
 printf("%d\n",i);   //�������ĸ���
 getchar();
 return 0;
}
