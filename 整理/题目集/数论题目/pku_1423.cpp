//�ο�
//http://hi.baidu.com/nash635/blog/item/250a947fc9ad720c29388a00.html

#include <iostream>
#include <cmath>
using namespace std;

const double e = 2.7182818284590452354, pi = 3.141592653589793239;

int main()
{
    int n, m ;
    double Digits;
    cin>>n;
    while (n--) {
        cin>>m;
        Digits = 0.0;
        if (m < 100000) {
            for (int i = 1; i <= m; ++i)
                Digits += log10(i*1.0) ;
        }        
        else {        
            //1.����λ����(int)long10(n)+1
            //2.stirling��ʽ---��Ϊ��һ�����ƹ�ʽ,����
            //  ������m��С��ʱ��,���ܹ�ʹ�ù�ʽֱ�Ӽ���
            // �ѹ�ʽ�е�sqrt©����,���Ҹ��˺þ�!!!!!!!
            Digits = log10(sqrt(2*pi*m)) + m*log10(m/e);
        }
        m = int(Digits);
        if(m <= Digits)
            ++m;
        cout<<m<<endl; 
    }
    return 0;
}

