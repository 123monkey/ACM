
#include <fstream>
using namespace std;

long long f[10000]={0,0,1,2};
// f[i]ָi��������ʱ�еķ�������

ifstream fin("book.in");
ofstream fout("book.out");

int main(void)
{

	long all,i;
	
	fin>>all;
	
	for(i=3;i<=all;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]); 
		
	fout<<f[all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
