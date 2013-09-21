/*
pku-2181 Jumping Cows
http://acm.pku.edu.cn/JudgeOnline/problem?id=2181

�Ѹ�����һϵ��ֵ������ϵ�б�ʾ����,������������һ����������,
������������������,ż�������Ǽ���.������������Ҫ���ϴ���"����"����ֵ,
ż������Ҫ��ȥ����"����"����ֵ,���ұ�֤���������е���Ծ������������,��
�������������ȷ���.
*/


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    
    int p;
    cin>>p;
    vector<double> v(p,0);
    vector<double> res;
    
    int i, j;
    for (i = 0; i < p ; ++i) {
        cin>>v[i];
    }
    double pre = INT_MIN;
    int c = 0;
    for (i = 0; i < p; ++i) {
        j = i;
        if (c == 0) {
            while (j+1 < p && v[j+1] > v[j]) {
                pre = v[j++];
            }
            res.push_back(v[j]);
            //cout<<"����"<<v[j]<<endl;
        }
        if (c == 1) {
            while (j+1 < p  && v[j+1] < v[j]) {
                pre = v[j++];
            } 
            res.push_back(-v[j]);
           // cout<<"����: "<<-v[j]<<endl;
        }
        i = j;
        c = (c+1)%2;  
    }

    if (res[res.size()-1] < 0) { //������һ����ֵΪ��,��ȡ��,�൱���˻�һ��
        res[res.size()-1] = 0;
    }
    printf("%.lf\n",accumulate(res.begin(), res.end(), 0.0) );
    
    return 0;
}


