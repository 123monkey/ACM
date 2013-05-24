/*
ŷ��·:��һ����ͨͼ�У��ҵ�һ��·������ÿ���߶������ҽ�����һ�Ρ�

ŷ��·��ŷ����·���㷨��һ����,��������:
1.ŷ��·Ҫ��������ҽ���2����Ķ�Ϊ����;
  �����������Դ�ͻ�,�������������,���ֻ�ܴ�����������ȡһ��;
2.��ŷ����·�������е�Ķȶ���ż��(N*);
  �����һ�����Ϳ�����;

3.ͨ���õ��㷨������dfs����,ֻ�ǰѸվ����ı�ɾ��;
  Ȼ��Ѷ�Ϊ0�����β���ͳ���ŷ��·;
*/

//zhulei632 2008-05-15
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> stk;
int n,  m;       //n-������Ŀ; m-�ߵ�����.
vector<vector<int> > mat; //�ڽ���,����Ϊ1,����Ϊ0
vector<int> ans; //ŷ��·�еĶ�������
int start = 0;   //ŷ��ͨ·�����

//�ж��Ƿ����ŷ��ͨ·
bool IsExitsEulerRoute()
{
    int num = 0;
    
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j = 0; j < n; ++j) 
            tmp += (mat[i][j]);// + mat[j][i]);        
        
        if (tmp%2 == 1) {//����Ϊ����?
            ++num;
            start = i;
        }
    }
    //0����2�����������,�����ŷ��ͨ·
    if (num == 0 || num == 2) 
        return true;
    else 
        return false;
}

//��ȱ���
void dfs(int vex) 
{
    stk.push(vex);
    for (int i = 0; i < n; ++i) {
        if (mat[i][vex] != 0) {
            mat[i][vex] = mat[vex][i] = 0;
            dfs(i);
            break;
        }
    }
    return ;
}

//Ѱ��ŷ��ͨ·
void findEulerRoute(int start)
{
    int i, top;

    stk.push(start);
    while (!stk.empty()) {        
        top = stk.top();
        stk.pop();

        //Ѱ�Ҷ���Ϊ0�ĵ�
        bool flag = false;
        for (i = 0; i < n; ++i) {
            if (mat[top][i] > 0) {
                flag = true;  
                break;
            }
        }
        //û�е������չ
        if (flag == false)
            ans.push_back(top+1);
        //��������չ
        else 
            dfs(top);            
    }    
}

int main()
{
    int from, to;
    
    cin>>n;
    mat = vector<vector<int> >(n, vector<int>(n, 0));
    
    cin>>m;
    //mat�д��±�0��ʼ������
    for (int i = 0; i < m; ++i) {
        cin>>from>>to;
        mat[from-1][to-1] = 1; 
        mat[to-1][from-1] = 1;
    }
    
    if (IsExitsEulerRoute()) {
        findEulerRoute(start);
        for(int i = 0; i < ans.size(); ++i) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"No euler route exists."<<endl;
    }
    return 0;
}

/*

��������:
����:
6 6

1 2 
1 6
2 6
3 4
4 5
5 6
���:
3 4 5 6 2 1 6

*/