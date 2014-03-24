#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926;

int main()
{
    int D, V;
    while (cin>>D>>V && !(D==0 && V==0)) {
        //Բ̨�����ʽ: ��� = pi*h*(R^2+R*r+r^2)/3,����,r��R�ֱ�Ϊ���µװ뾶,hΪԲ̨�߶�
        printf("%.3lf\n", pow(D*D*D*1.0-6.0*V/pi,1.0/3));
    }
    return 0;
}
