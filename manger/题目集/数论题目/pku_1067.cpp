
//pku-1067-ȡʯ����Ϸ(������->��������)
#include <iostream>
#include <cmath>
using namespace std;

const double q = (1+sqrt(5.0))/2.0; //�ƽ�ָ���
unsigned long a, b;

bool WythoffGame_win()
{
    /*
    ���ڵ�k���������(ak,bk),Ӧ����ak = k*q;
    ����,����(a,b)Ϊ��k���������(k=0,1,2,...),��ô����k=(b-a),
    Ȼ��,���ж�a��(int)(k*q),�����,��Ϊ�������,�ذ�;�����ʤ.
    */
    if (a > b)
        std::swap(a, b);
    int k = b-a;
    if (a == (unsigned long)(k*q)) {
        return false;
    }
    return true;    
}

int main()
{
    while(cin>>a>>b) {
        cout<<WythoffGame_win()<<endl;
    }
    return 0;
}
