#include <iostream>
#include <cmath>
using namespace std;
// ���,��Ȼ��ô�������Ŀ����
// ֻ��Ҫ�ж���������n�Ƿ���2���������ݾͿ�����

int main()
{
    double n;
    int exp;
    while (cin>>n) {
        if(frexp(n, &exp) == 0.5)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;   
    }//while
    return 0;
}
