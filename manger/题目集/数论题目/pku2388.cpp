//����������������ͬ������ �ҳ��м��С���Ǹ��������

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, low, high; 
    cin>>n;
    vector<double> a(n, 0);
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    low = 0;
    high = n - 1; 
    while (low < high) {
        ++low;
        --high;
    }
    cout<<a[low]<<endl;
    return 0;
}