/*
http://www.wangchao.net.cn/bbsdetail_38136.html��
������ķ�����������������Ľ׳˽��Խ������⡣
�����㷨��������ʵ�ĳ˷�����˼�룬���λϸϸ��ζ��
 */
#include <stdio.h>
#include <memory.h>

//����n�Ľ׳�, int a[]������, ���ؽ׳�λ��digits
//����: int digits = bignumber_factorial(n, a);
int bignumber_factorial(int n, int *a)
{
	memset(a, 0, sizeof(a)), a[0] = 1;
    int nCarry, nDigits = 1; //��λ, λ��
         //������ȳ�ʼ��Ϊ1
    int temp;      //�׳˵���һԪ������ʱ�����ĳλ�ĳ˻����

    for(int i = 2; i <= n; ++i)    { //��ʼ�׳ˣ��׳�Ԫ�ش�2��ʼ���Ρ��ǳ���
        //��������ĳ˷�����˼�������ǣ�����ʱ�����ÿλ��׳�Ԫ�����
        for(int j = 1, nCarry = 0; j <= nDigits; ++j) {
            temp = a[j-1] * i + nCarry; //��Ӧ�׳��е�һ���뵱ǰ������ʱ�����ĳλ��ˣ����Ͻ�λ��
            a[j-1] = temp % 10; //������ʱ�����λ����Ϣ
            nCarry = temp / 10; //���Ƿ��н�λ
        }
        while(nCarry) { //������λ�н�λ
            a[++nDigits-1] = nCarry % 10; //�¼�һλ�������Ϣ��λ����1
            nCarry /= 10; //�����ܲ��ܼ�����λ
        }
    }
	return nDigits;
}

int main()
{
	int a[10000];   //ȷ�����������������������㹻��

    int n;         //�׳˴�С
    printf("������n�Ĵ�С(С��2000):");
   // scanf("%d",&n);//�Ӽ��̽��ս׳˴�С
    n = 20;
	int digits = bignumber_factorial(n, a);

    printf("�����:\n%d ! = ", n); //��ʾ���
    for(int j = digits; j >=1; --j) {
        printf("%d",a[j-1]);
    }
	putchar('\n');

    return 0;
}
