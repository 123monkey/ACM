#include<iostream>
using namespace std;

/*
//ɸ������������ MAXNΪ���Χ
#include <cmath>
#define MAXN  4000000
#define pMaxCount 300000
int  pCount; //MAXN���ڵ���������,���28����
bool prime_hash[MAXN+1];
int  plist[pMaxCount]; //������,��С��0��ʼ��

inline void init_prime()
{
    int i, j, idx, max = (int)sqrt(MAXN*1.0);
    //prime_hash[i] = true,(i>=2)��ʾiΪ����
    memset(prime_hash,true,sizeof(prime_hash));
    for(i = 2 ; i <= max; ++i) {
        if(prime_hash[i])
            for(j = i*i; j <= MAXN; j += i)
                prime_hash[j] = false;
    }
    //����������������plist��
    for(idx = 0, i = 2; i <= MAXN; ++i)
        if(prime_hash[i] == true) {plist[idx] = i;++idx;}
    pCount = idx;
//  cout<<pCount<<endl;
}
*/
/////////////////////////////////////////////////////////
//���������ж�����,�ȵ���initprime
int plist[300000],pcount=0;

int prime(int n){
    int i;
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (i=0;plist[i]*plist[i]<=n;i++)
        if (!(n%plist[i]))
            return 0;
    return n>1;
}

void initprime2(){
    int i;
    for (plist[pcount++]=2,i=3;i<4000000;i++)
        if (prime(i))
            plist[pcount++]=i;
}

int main()
{
    initprime2();
    //init_prime();
    cout<<"over....."<<endl;
    //*****

    return 0;
}
