
#include <fstream>
using namespace std;

long long f[10000];
// f[i]ָ��2*i����������������Ҫ�ĳ����θ���

ifstream fin("domino.in");
ofstream fout("domino.out");

int main(void)
{
	
	long all,i;
	
	fin>>all;
	
	f[0]=f[1]=1;
	
	for(i=2;i<=all;i++)
		f[i]=f[i-1]+f[i-2];
		
	fout<<f[all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
} 
