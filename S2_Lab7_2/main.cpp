#include <iostream>
#include <fstream>

using namespace std;

int kontor = 0;

int xlepes[] = {0, -1, 1, 0};
int ylepes[] = {-1, 0, 0, 1};

bool lehet(int i, int j,  short labirintus[][10], int N, int M )
{
    if (labirintus[i][j] > 0) {
        return false;
    }

    if (labirintus[i][j] == -1) {
        return false;
    }

    if (labirintus[i][j] == -2) {
        return false;
    }

    if (i<0 || i >= N || j < 0 || j>= M) {
        return false;
    }
    return true;
}
void kiir( short labirintus[][10], int N, int M )
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (labirintus[i][j] >= 0 && labirintus[i][j]< 10) cout << " ";
            cout << labirintus[i][j] << " ";
        }
        cout << endl;
    }
}

void backtracking(int sor, int oszlop, short labirintus[][10], int lepes, int N, int M )
{
    if(sor == N - 1  && oszlop == M - 1)
    {
        kontor++;
        kiir(labirintus, N, M);
        cout << endl;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(lehet(sor+xlepes[i], oszlop+ylepes[i],  labirintus, N, M))
        {
            short templabirintus[10][10];
            for(int i = 0; i< N; i++){
                for(int j = 0; j < M; j++){
                    templabirintus[i][j] = labirintus[i][j];
                }
            }
            int templepes = lepes + 1;
            templabirintus[sor+xlepes[i]][oszlop+ylepes[i]] = templepes;
            backtracking(sor+xlepes[i], oszlop+ylepes[i],  templabirintus,templepes, N, M);
        }
    }
}

int main()
{
    ifstream in("labirintus.txt");
    int N, M;
    in >> N;
    in >> M;

    short labirintus[10][10];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
           in >> labirintus[i][j];
        }
    }

    labirintus[0][0] = 1;
    backtracking(0,0, labirintus, 1, N, M);

    cout << kontor << endl;

    return 0;
}
