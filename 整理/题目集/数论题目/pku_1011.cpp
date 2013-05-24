#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int nSticks[68];
bool bUsed[68];

int nTotalSticks;

bool concatenate(int nUnusedSticks, int nLeft, int nLen)
//nUnusedSticks-δ���ù���ľ����;nLeft-����ƴ��ľ����ʣ�೤��;nLen-���ڳ��Ե�ԭʼ����
{
    //����ľ������ƴ�յ���ΪnLen��ԭʼľ����, ��ʣ�೤��Ϊ0
    //���ʾnLenΪ�����ԭʼ����
    if (nUnusedSticks == 0 && nLeft == 0) 
        return true;

    //�����ǰľ��ʣ��0,��ʼƴ����һ��ľ��
    if (nLeft == 0 ) 
        nLeft = nLen;

    for (int i = 1; i <= nTotalSticks; ++i) {
        //���ù����䳤�ȴ���nLeft
        if (bUsed[i] == true || nSticks[i] > nLeft)
            continue;

        //����ƴ������ƴ�յ�ľ��
        bUsed[i] = true; 
        if (concatenate(nUnusedSticks-1, nLeft-nSticks[i], nLen) == true) 
            return true;

        //�˳��ϴγ��Ե�ľ��,׼��������һ��ľ��
        bUsed[i] = false;
        //�����ǰ���Ե���ĳ��ԭʼľ���еĵ�һ��λ�û����һ��λ��,
        //���ҵ�������ʧ��,�򲻱��������λ���ϳ������µ�ľ��
        if (nSticks[i] == nLeft || nLeft == nLen)
            break;
    }//for

    return false;
}//concatenate()

int main()
{
    int nTotalLen, nLen, i;
    
    while (cin>>nTotalSticks && nTotalSticks != 0) {    
        memset(nSticks, 0    , 68*sizeof(int));
        memset(bUsed, false, 68*sizeof(bool));
        
        nTotalLen = 0;
        for (i = 1; i <= nTotalSticks; ++i) {
            scanf("%d", &nSticks[i]);
            nTotalLen += nSticks[i];
        }

        sort(nSticks+1, nSticks+1+nTotalSticks, greater<int>());
    
        for (nLen = nSticks[1]; nLen <= nTotalLen; ++nLen) {
            if (nTotalLen%nLen == 0 && concatenate(nTotalSticks, 0, nLen)) {
                    printf("%d\n", nLen);
                    break;
            }
        }//for
    }//while
    return 0;
}
