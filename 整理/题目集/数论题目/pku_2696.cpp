//̫����ظ�������,���˵ݹ�ʵ��,����Ϊ��!

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,a, b, c, d, e, f, g, h, i;
    cin>>n;
    while (n--) {
        cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
        vector<int> v(i+1,0);
        v[0] = a; v[1] = b; v[2] = c;
        for (int p = 3; p <= i; ++p) 
            if (p%2 == 1)
                v[p] = ((d*v[p-1] + e*v[p-2] - f*v[p-3])%g+g)%g; //ע��ȡģ�������Ϊ��,(nVal%g+g)%g�ɽ�nVal%g�������Ϊ����
            else 
                v[p] = ((f*v[p-1] - d*v[p-2] + e*v[p-3])%h+h)%h;
            cout<<v[i]<<endl;
    }//while
    return 0;
}
