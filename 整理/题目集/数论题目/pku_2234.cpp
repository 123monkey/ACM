
//pku-2234-Matches Game-������->��ķ����(Nimm Game)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ConvertDecimalToOthers(long n, int nBase)
{
    string strDigits ="0123456789ABCDEF", strVal = "";
    long rem = n%nBase; //����
    while (rem != n) {//���һλ?    
        strVal = strDigits[rem] + strVal;
        n = n/nBase;
        rem = n%nBase;
    }
    strVal = strDigits[rem] + strVal;
    if (strVal.length() < 25) {
        strVal = string(25-strVal.length(), '0')+strVal;
    }
    return strVal;
}

int main()
{
    int m, a, i, j, t;
    bool flag;
    while(cin>>m) {
        flag = false;
        vector<string> v(m);        
        for (i = 0; i < m; ++i) {
            cin>>a;
            v[i] = ConvertDecimalToOthers(a, 2); //ת�����ƴ����
  //          cout<<v[i]<<endl;
        }
        for (i = 0; i < 25; ++i) {
           t = 0;
            for (j = 0; j < m; ++j) {
                t += (v[j][i]-'0');
            }
            if (t%2 == 1) { //���������,��ȡ��ʤ!
                printf("Yes\n");
                flag = true;
                break;
            }
        }
        if (flag == false) {
            printf("No\n");
        }
    }
    return 0;
}
