#include <iostream>

using namespace std;

const int N = 5;

int kontor = 0;

int xlepes[] = {-1,-2,-2,-1,1,2,2,1};
int ylepes[] = {-2,-1,1,2,2,1,-1,-2};

bool lehet(int i, int j,  short board[][N])
{
    if (board[i][j] > 0) {
        return false;
    }

    if (i<0 || i >= N || j < 0 || j>= N) {
        return false;
    }

    return true;
}

void uresit( short board[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
}

void kiir( short board[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool backtracking(int sor, int oszlop, short board[][N], int lepes )
{
    if(lepes == N*N)
    {
        kontor++;

        kiir(board);
        cout << endl;

        return true;
    }
    //ha nem, kezdjuk az elso oszloptol, s probaljuk meg lerakni valahova a kovetkezo kiralynot
    for(int i = 0; i < 8; i++)
    {
        //ha le lehet tenni a jelenlegi helyre a kiralynot
        if(lehet(sor+xlepes[i], oszlop+ylepes[i],  board))
        {
            //hozzunk letre egy ideiglenes tablat, amibe atmasoljuk az eddigit
            short tempboard[N][N];
            for(int i = 0; i< N; i++){
                for(int j = 0; j < N; j++){
                    tempboard[i][j] = board[i][j];
                }
            }
            int templepes = lepes + 1;
            //az ideiglenes tablara tegyuk le a kiralynot
            tempboard[sor+xlepes[i]][oszlop+ylepes[i]] = templepes;
            //hivjuk meg a backtraking fuggvenyt a kovetkezo sorra
            backtracking(sor+xlepes[i], oszlop+ylepes[i],  tempboard,templepes);
        }

    }
}



int main()
{
    //sakktabla letrehozasa
    short board[N][N];
    //sakktabla inicializalasa
    uresit(board);
    //backtracking inditasa a 0. sorbol
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            uresit(board);
            board[i][j] = 1;
            backtracking(i,j, board, 1);
        }
    }


    cout << kontor << endl;

    return 0;
}
