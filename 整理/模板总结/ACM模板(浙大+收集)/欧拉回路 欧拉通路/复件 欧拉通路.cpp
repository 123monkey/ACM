/*ŷ��·�㷨
1����һ�������ջ(�����������ͼһ����һ������������ջ)
2����ջ��Ԫ�ؿ�ʼ����ͼ����������ȱ�����������һ���߾Ͱ�������ɾ����һֱ��ĳһ��û�����������ıߡ�
3����ջ��Ԫ���������ջ�����ջû�п�ת��2��
*/
//�ο�����
// http://liymouse.bokee.com/5054182.html
//����һ������ͼ�����ж��Ƿ����ŷ��·���������һ��ŷ��·
//�����붥�����ͱ�����֮������ÿ�������ӵ�2����
//����
//5 6   (5���㣬6����)
//1 2
//1 3
//2 3
//2 4
//2 5
//4 5

#include <stdio.h>
#include <string.h>

struct stack{int top , node[210];} f; //����Ķ�ջ
int a[201][201]; //ͼ���ڽӾ���

int n;

void dfs(int x)     //ͼ��������ȱ���
{
	int i;
    f.top ++; f.node[f.top] = x;
    for (i = 1; i <= n; i ++)
        if (a[i][x] > 0) {
            a[i][x] = 0; a[x][i] = 0;   //ɾ���˱�
            dfs(i);
            break;
        }
}

void Euler(int x)   //ŷ��·�㷨
{
	int i , b;
    f.top = 0; f.node[f.top] = x;   //��ջ
    while (f.top >= 0) {
        b = 0;
        for (i = 1; i <= n; i ++)
			if (a[f.node[f.top]][i] > 0) {
				b = 1;
				break;
			}
			if (b == 0) {  //���û�е������չ���������ջ
				printf("%d ", f.node[f.top]);
				f.top --;
			}
			else {
				f.top --;
				dfs(f.node[f.top+1]);
			}      //����У���DFS
    }
}

int main()
{
	int m , from , to;
	int tmp, num, start, i , j , s;

    //input
    scanf("%d %d" , &n , &m); //n������  m����
    memset(a , 0 , sizeof(a));
    for (i = 0; i < m; i ++) {
        scanf("%d %d" , &from , &to); //�ߵ����˵�
        a[from][to] = 1;
		a[to][from] = 1;
    }


    {//�ж��Ƿ����ŷ����·
        num = 0;
        start = 1;
        for (i = 1; i <= n; ++i) {
            tmp = 0;
            for (j = 1; j <= n; ++j)
                tmp += a[i][j];
            if (tmp % 2 == 1) {
                start = i;
                ++num;
            }
        }
    }

    if ((num == 0) || (num == 2))
		Euler(start);
    else
		printf("No Euler path\n");

    getchar();
	getchar();
    return 0;


}
