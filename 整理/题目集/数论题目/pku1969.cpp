#include<iostream>
#include<math.h>
using namespace std;

long int a[3301];//�������е�r�������ֵĸ���

int main()
{
    long int num;
    long int r,i, j, t_num;
    bool f;
    for (r = 1; r <= 3300; ++r) {
        a[r] = r*(r+1)/2;
    }
    
    while (cin>>num) {
        f = false;
        for (r = 0; r <= 3300; ++r) {
            if (a[r]+1 <= num && num <= a[r+1]) {//���жϵ�num������һ���ڵ�r����
                t_num = a[r]+1;
                r = r+1;
                //����r�������л���ż������ȷ��i,j��ֵ.���е�һ�ο�ʼ.
                if ((r+1)%2 == 1) { 
                    i = r;
                    j = 1;
                    while (t_num < num) {
                        --i;
                        ++j;
                        ++t_num;
                    }
                }//if
                else {
                    i = 1;
                    j = r;
                    while (t_num < num) {
                        ++i;
                        --j;
                        ++t_num;
                    }                    
                }//else
                printf("TERM %ld IS %ld/%ld\n", num, j, i);
            } //if
            if (f == true) {
                break;
            }//if
        }//for
        
    }//while
    
    return 0;
}
