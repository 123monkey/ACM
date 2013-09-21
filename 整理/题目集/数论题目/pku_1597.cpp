#include <iostream>
using namespace std;

int main()
{
    long step, mod, seed, i;
    while (cin>>step>>mod) {
        seed = 0;
        bool bGood = true;
        for (i = 1; i < mod; ++i) {
            seed = (seed+step)%mod;
            if (seed == 0) { 
                //����ȡģ,�������ջ��γ�һ��ѭ��,��Ϊ��ʼΪ0,
                //����,����������mod������֮ǰ�ֳ���������0,��Ϊbad
                bGood = false;
                break;
            }
        }
        if (bGood == true)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);
    }
    return 0;
}


/*
AC
#include <iostream>
using namespace std;

int main()
{
    bool bFlags[100001];
    long step, mod, seed, i;
    while (cin>>step>>mod) {
        memset(bFlags, false, 100001);
        seed = 0;
        bFlags[0] = true;
        bool bGood = true;
        for (i = 1; i < mod; ++i) {
            seed = (seed+step)%mod;
            if (seed == 0) { //����ȡģ,�������ջ��γ�һ��ѭ��,��Ϊ��ʼΪ0,
                //����,����������mod������֮ǰ�ֳ���������0,��Ϊbad
            //if (bFlags[seed] == true) {//��������Ѿ����ֹ���
                bGood = false;
                break;
            }
            else 
                bFlags[seed] = true;
        }
        if (bGood == true)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);
    }
    return 0;
}
*/