#include <iostream>
using namespace std;

//��ȡģ-����ƽ����
inline long modular_exponentiation(long a, long b, long n)
{    
    __int64 d = 1;    
    long c = 0, nlen = 0;
    short Bin[34];//����b�Ķ�����λ,Bin[0]Ϊ���λ,Bin[nlen]Ϊ���λ

    while (b%2 != b) {
        Bin[nlen++] = b%2;
        b >>= 1;
    }
    Bin[nlen] = b;
    
    for (long i = nlen; i >= 0; --i) {
        c = 2*c;
        d = (d*d)%n;
        if (Bin[i] == 1 && ++c) {
            ++c, d = (d*a)%n;
        }
    }
    return d;
}

int main()
{
    long z, m, h, a, b, tmp;
    cin>>z;
    while (z--) {
        cin>>m>>h;
        tmp = 0;
        for (long i = 0; i < h; ++i) {
            cin>>a>>b;
            tmp += modular_exponentiation(a, b, m);
        }
        cout<<(m+tmp%m)%m<<endl;
    }
    return 0;
}
