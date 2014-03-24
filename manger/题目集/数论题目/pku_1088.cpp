/*
��anMaxLen[i][j]��¼�ӵ�anHeight[i][j]���������·��(��ʼ��ʱû������,ֻ���Լ�,Ҳ���ǳ�ʼֵΪ1)
״̬ת�Ʒ���anMaxLen[i][j]=max{opt[i+1][j], anMaxLen[i-1][j], anMaxLen[i][j+1], anMaxLen[i][j-1]} + 1   ��
Ҳ����˵, anMaxLen[i][j]��ֵ���ڴ�anHeight[i][j]�����������ĸ���������������ֵ+1��
������Ⲣ���Ǽ򵥵Ķ���,����anMaxLen[i][j]�Ĺ�����Ҫ����DFS�ĵݹ鷽��.����Ǽ��仯����.
*/

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////
short delta_x[] = {-1,+1,0,0};
short delta_y[] = {0,0,-1,+1};

long nRow, nColum, x0, y0, tmp;
long anHeight[102][102], anMaxLen[102][102];
//////////////////////////////////////////////////////////////////////////

int get_max_len(int x, int y)
{
    if (anMaxLen[x][y] != 1)
        return anMaxLen[x][y];

    long max = -1;
    for (int i = 0; i < 4; ++i) {//����Χ�ĸ��������̽��.
        x0 = x+delta_x[i];
        y0 = y+delta_y[i];
        if (x0 < 1 || x0 > nRow || y0 < 1 || y0 > nColum) {
            continue;
        }
        if (anHeight[x][y] > anHeight[x0][y0]) {
            tmp = get_max_len(x0, y0);
            if (anMaxLen[x][y] < tmp+1) {
                anMaxLen[x][y] = tmp+1;
            }
        }
    }
    return anMaxLen[x][y];
}
//////////////////////////////////////////////////////////////////////////

int main()
{
    cin>>nRow>>nColum;
    int i, j;
    for (i =1; i <= nRow; ++i) {
        for (j = 1; j <= nColum; ++j) {
            scanf("%d",&anHeight[i][j]);
            anMaxLen[i][j] = 1;//��ʼֻ�����㱾��,���򳤶�Ϊ1
        }
    }

    long maxLen = -1;
    for (i =1; i <= nRow; ++i) {
        for (j = 1; j <= nColum; ++j) {
            if (maxLen < get_max_len(i,j)) {
                maxLen = anMaxLen[i][j];
            }
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
