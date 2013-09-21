#include<iostream>
#include<string>
#include<vector>
using namespace std;

inline void print_str(string str)
{
    while(str.length() > 50) 
    {
        cout<<str.substr(0,50)<<endl;
        str = str.substr(50);
    }
    cout<<str<<endl;
}

int main()
{
    string chars = "0123456789";
    long a, b;
    string str;
    vector<long> pos;
    while(cin>>a>>b && a+b) 
    {
        pos.assign(b, -1);
        str = ".";
        int i = 0;
        pos[a] = 0;//��Ϊa<b,���Ը�λһ��Ϊ0
        while(1)
        {
            ++i;//����С���ĵ�iλ, ��1��ʼ
            a *= 10;
            str += chars[a/b]; 
            a %= b;
            if(a == 0)//����Ϊ��,��������
            {
                print_str(str);
                puts("This expansion terminates.");
                break;
            }
            else if(pos[a] != -1)//����a֮ǰ�Ѿ����ֹ�,����ѭ��
            {
                print_str(str);
                printf("The last %d digits repeat forever.\n", i-pos[a]);
                break;
            }
            else 
                pos[a] = i;//������С���еĵ�1λ��,����Ϊa         
        }
    }
    return 0;
}
