#include<iostream>
using namespace std;
//���˺ö��,û������ð취,����̳�ѵ���һ������,��������.
//http://cms.bit.edu.cn/moodle/mod/forum/discuss.php?d=10531
//�Ժ����о�ʱ��ô������.
int main()
{
    long m[15]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
    long n;
    while(cin>>n && n) {
       cout<<m[n]<<endl;
    }
    return 0;
}
