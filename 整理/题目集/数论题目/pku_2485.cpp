#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct  {
    int from, to,weight;
}edge;

vector<edge> edges;

bool edgeCmp(const edge& a, const edge& b)
{
    return a.weight < b.weight;
}

void union_set(vector<int>& sets, int n, int from, int to)
{
    int j;
    if(sets[from] < 0 && sets[to] < 0) {
        int t = sets[to];
        for (j = 1; j <= n; ++j) {//�ϲ�����
            if(sets[j] == t)
                sets[j] = sets[from];
        }
    }
    else if(sets[from] < 0 && sets[to] > 0) {
        sets[to] = sets[from];
    }
    else if(sets[from] > 0 && sets[to] < 0) {
        sets[from] = sets[to];
    }
    else if(sets[from] > 0 && sets[to] > 0) {
        sets[from] = sets[to] = -sets[from];
    }            
}

int MST_Kruskal_pku2421(int n)
{
    //���еı߰�Ȩֵ�ǽ�������
    sort(edges.begin(), edges.end(), edgeCmp);
    
    int  nMaxLen = -1000,
        nEdgeNum = edges.size(),//�ߵ�����
        i, from, to;
    
    vector<bool> used(nEdgeNum+1, false); //���ÿһ�����Ƿ��Ѿ���������������
    vector<int> sets(n+1);    //��¼ÿһ���������ļ���
    for(i = 1; i <= n; ++i) {
        sets[i] = i;//��ʼʱ, ÿ�����㵥������һ������
    } 
    
    //Ѱ��Ȩֵ��С�İ�ȫ�߼���,ֱ��������С������
    for (i = 0; i < nEdgeNum; ++i) {
        from = edges[i].from;
        to = edges[i].to;
        
        //�ڵ�from �� to ����ͬһ���ϻ��������ǵı��Ѿ��ù���,���������ÿ���
        if (sets[from] == sets[to] || used[i] == true) {
            continue;
        }
        else {
            union_set(sets, n, from, to);
            nMaxLen = edges[i].weight;
        }        
    }
    return nMaxLen;
}

int main()
{
    int t, n, i, j, w;
    cin>>t;
    while (t--) {
        cin>>n;    
        edges = vector<edge>(n*(n-1)/2);
        int index = 0;
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                scanf("%d", &w);
                if (w > 0 && j >= i) {
                    edges[index].weight = w;
                    edges[index].from = i;
                    edges[index].to = j;
                    ++index;
                }                        
            }        
        }
        cout<<MST_Kruskal_pku2421(n)<<endl;
    }
    return 0;
}

