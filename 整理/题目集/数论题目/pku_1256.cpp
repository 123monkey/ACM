#pragma warning(disable:4786)
#include <iostream>
#include <algorithm>
using namespace std;

int myPre(const char& a, const char& b)
{
    if (a == b|| a+32 == b || a == b+32)//ֻ�д�Сд֮�ֵ���ĸ�Ƚ�
        return a < b;
    else//��ͬ����ĸ�Ƚ�
        return toupper(a) < toupper(b);
}

int main()
{
    int n, len;
    char str[15];
    cin>>n;
    while (n--) {
        scanf("%s", str);
        len = strlen(str);
        sort(str, str+len, myPre);

        printf("%s\n",str);
        while(next_permutation(str, str+len, myPre)){
            printf("%s\n", str);
        }
    }
    return 0;
}




