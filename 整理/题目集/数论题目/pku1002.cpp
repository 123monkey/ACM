/*
���˼·:
    ��ת��Ϊ���ִ������������Ȼ���������ظ����ֵĺ���ʹ�����
����,��ʹ���ÿ��ţ�ʱ�����Ҳ��O(N*log2N+N),������Ŀ�е���������һ��
�ᳬʱ��,���Ա����ҵ�һ������ʱ������ɵķ���.
    Ҳ�����������Ϸ���,�޸��˺ܶ�ζ�TLE,���Ƿ���.
�Ľ�:
    �����۰����ķ����洢ת���������,�������ܱ�֤����������洢��,���������,
ֱ�ӱ�������ظ���Ԫ�ؼ���.

����辶:    
    Ϊ��ʵ���������,����STL��׼���е�map����,��Ϊ���ڲ����ɶ�������ʵ�ֵ�,���Բ���
ʱ�Ĵ��ۺ�Сlog2N,���䵱����������ʹ��,ʡȥ�˲��ٴ���.
*/
#pragma  warning(disable: 4786)//��vc6.0�±�������ϴ���
#include <iostream>
#include <map>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////
//             A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
int valus[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
typedef map<long, int, less<long> > LongIntMap;
//////////////////////////////////////////////////////////////////////////

int main()
{
    bool flag = false;
    long n, i,  tmp ; 
    LongIntMap mymap;
    LongIntMap::const_iterator itr;    
    
    cin>>n;    
    
    string str;    
    for (long k = 0; k < n; ++k) {
        cin>>str;
        tmp = 0;
        int len = str.size();
        
        for (i = 0; i < len; ++i) {
            if ( isdigit(str[i]) )
                tmp = tmp*10 + (str[i] -'0');
            else if ( isalpha(str[i]) ) 
                tmp = tmp*10 + valus[str[i] -'A'];    
        }
        mymap[tmp]  += 1;
    }
    
    for (itr = mymap.begin(); itr != mymap.end(); ++itr) {
        if (itr->second > 1) {
            printf("%03d-%04d %d\n", itr->first/10000, itr->first%10000, itr->second);
            flag = true;
        }
    }

    if (flag == false) {
        cout<<"No duplicates."<<endl;
    }
    return 0;
}
