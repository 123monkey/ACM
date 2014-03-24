#include <iostream>
#include <vector>
#include <string>
using namespace std;

class pos {
public:
    char direct;  //����
    int  step;    //����õ�ʱ�߹��Ĳ���
    bool  visited;//���ʱ��
    pos():step(0), visited(false){};
    
};

int nRows, nColums, nPosStart;
vector<vector<pos> > board;

int move(int i, int j)
{    
    int steps = 1;
    while (1) {
        board[i][j].visited = true;
        board[i][j].step = steps;

        switch(board[i][j].direct) {
            case 'N':    --i; break;
            case 'S':    ++i; break;
            case 'W':    --j; break;
            case 'E':    ++j; break;
        }
        
        if (i < 0 || i >= nRows || j < 0 || j >= nColums) {
            printf("%d step(s) to exit\n", steps);
            return 0;
        }
        else if(board[i][j].visited == true){
            printf("%d step(s) before a loop of %d step(s)\n", board[i][j].step-1, steps-(board[i][j].step-1));
            return 0;
        }        
        else {
            ++steps;
        }
    }
}

int main()
{
    int i, j;
    while (cin>>nRows>>nColums>>nPosStart && nRows+nColums+nPosStart>0) {
        board = vector<vector<pos> >(nRows, vector<pos>(nColums));
        for (i = 0; i < nRows; ++i) {
            for (j = 0; j < nColums; ++j) {
                cin>>board[i][j].direct;
            }
        }
        move(0, nPosStart-1);
    }
    return 0;
}
